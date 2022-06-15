#define _GNU_SOURCE  // required for memem()
#define ARRY_MAX 32

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * __exit - exits with usage option and exits
 *
 * @str: filename for the executable program/code
 *
 * Return: nothing
*/
void __exit(char *str) {
	printf("\n\tUsage: %s PID SEARCH_TEXT REPLACE_TEXT\n\n", str);
	exit(1);
}

/**
 * main - Entry point
 *
 * Description: this is a C program to replace the python code for this
 *              Hack The Virtual Memory task. I haven't learnt python yet
 *              so I am using the C knowledge that I know to implement
 *              the python code, it will also be a learning opportunity
 *
 * Compile this way: gcc read_write_heap.c -o read_write_heap
 *
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 (Success) | 1 if it fails
*/

int main(int argc, char *argv[]) {
	int pid, errnum;
	char maps_file[FILENAME_MAX]; //FILENAME_MAX = 260
	char mem_file[FILENAME_MAX]; //FILENAME_MAX = 260
	char line[LINE_MAX]; // LINE_MAX == 2048
	char *search_string, *write_string;

	//check usage
	if (argc != 4)
		__exit(argv[0]);

	pid = atoi(argv[1]); //get pid from args
	search_string = argv[2]; //get search string from args
	write_string = argv[3]; //get replace string from args

	//check if our arguments are empty or below zero
	if (pid <= 0 || search_string == NULL || write_string == NULL)
		__exit(argv[0]);

	printf("[+] maps: /proc/%d/maps\n", pid);
	printf("[+] maps: /proc/%d/mem\n", pid);

	sprintf(maps_file, "/proc/%d/maps", pid);//get maps file
	FILE *maps = fopen(maps_file, "r"); //open file in read mode

	if (maps == NULL) {
		printf("[*] ERROR Can not open file %p\n", maps);
		fprintf(stderr, "        I/O error (%s)\n", strerror(errnum));
		exit(1);
	}

	char addr[ARRY_MAX], perm[ARRY_MAX], offset[ARRY_MAX];
	char device[ARRY_MAX], inode[ARRY_MAX], pathname[ARRY_MAX];

	//read maps file line by line
	while (fgets(line, sizeof(line), maps) != NULL) {
		//get line that contains the string [heap]
		if ((strstr(line, "[heap]")) != NULL)
		{
			/*
			 * we get to split the line into tokens and copy
			 * the tokens into new array variables
			*/
			printf("[*] Found [heap]:\n");

			strcpy(addr, strtok(line, " "));
			strcpy(perm, strtok(NULL, " "));
			strcpy(offset, strtok(NULL, " "));
			strcpy(device, strtok(NULL, " "));
			strcpy(inode, strtok(NULL, " "));
			strcpy(pathname, strtok(NULL, " "));

			printf("\tpathname = %s", pathname);
			printf("\taddresses = %s\n", addr);
			printf("\tpermisions = %s\n", perm);
			printf("\toffset = %s\n", offset);
			printf("\tinode = %s\n", inode);
		}
	}

	//check for permissions in the heap
	if (perm[0] != 'r') {
		printf("[*] ERROR %.6s does not have read permission\n", pathname);
		fclose(maps);
		exit(0);
	} else if (perm[1] != 'w') {
		printf("[*] ERROR %.6s does not have write permission\n", pathname);
		fclose(maps);
		exit(0);
	}

	int count = 0;
	char *temp = addr;
	unsigned long int start_addr, end_addr;

	//get start and end of the heap in the virtual memory
	while (temp != NULL) {
		char *end = NULL;

		//reset errno to zero before call
		errno = 0;

		start_addr = strtoul(addr, &end, 16);
		if (addr == end) {
			printf("[*] ERROR parsing of starting address of the heap [ %s ] address failed\n.", addr);
			fclose(maps);
			exit(1);
		} else if ((start_addr == LONG_MAX || start_addr == LONG_MIN) && errno == ERANGE) {
			printf("[*] ERROR out of range while parsing for starting address from heap address: %s\n", addr);
			fclose(maps);
			exit(1);
		} else {
			char *end2 = NULL;

			if (*end == '-')
				end++;

			end_addr = strtoul(end, &end2, 16);
			if (end == end2) {
				 printf("[*] ERROR parsing of ending address of the heap [ %s ] address failed\n.", addr);
				 fclose(maps);
				 exit(1);
			} else if ((end_addr == LONG_MAX || end_addr == LONG_MIN) && errno == ERANGE) {
				printf("[*] ERROR out of range while parsing for starting address from heap address: %s\n", addr);
				fclose(maps);
				exit(1);
			} else if (*end2 != '\0') {
				//never trust your os
				printf("[*] ERROR wrong address format\n");
				fclose(maps);
				exit(1);
			} else
				temp = NULL;
		}
		printf("\tAddr start [%lx] | end [%lx]\n", start_addr, end_addr);
	}

	sprintf(mem_file, "/proc/%d/mem", pid); //get mem file
	int mem = open(mem_file, O_RDWR); //open binary file in read and write mode
	
	if (mem == -1) {
		printf("[*] ERROR Can not open file mem %d	\n", mem);
		fprintf(stderr, "        I/O error (%s)\n", strerror(errnum));
		close(mem);
		exit(1);
	}

	lseek(mem, start_addr, SEEK_SET); //move file position to start_addr
	int len = end_addr - start_addr;
	char *buff = (char *)malloc(len * sizeof(char)); // buffer to store our specific file contents

	if (buff == NULL) {
		printf("[*] ERROR Creating buffer.");
		free(buff);
		return (1);
	}

	read(mem, buff, len); // read size = len and store in our buffer
	void *found = memmem(buff, len, search_string, strlen(search_string)); // search for string in buffer
	int index = found - (void *)buff;

	if (found != NULL) {
		/*
		* (void *)start is the start of address of our dynamic allocating memory
		* found - start gets us our index
		* src: https://stackoverflow.com/a/59221103/12076640
		*/
		printf("[*] Found '%s' at %x\n", search_string, index);
		free(buff);
	} else {
		printf("[*] Can't find '%s'\n", search_string);
		free(buff);
	}

	//writing
	printf("[*] Writing '%s' at %lx", write_string, start_addr + index);
	lseek(mem, start_addr + index, SEEK_SET); //move file position to start_addr
	if (write (mem, write_string, strlen(write_string)) == -1) {
		printf("[*] ERROR faced when writting\n");
		close(mem);
		exit(1);
	}
	
	fclose(maps);
	close(mem);

	return (0);
}
