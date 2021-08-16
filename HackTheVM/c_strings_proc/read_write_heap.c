#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

#define ARRY_MAX 32

/**
 * __exit - exits with usage option and exits
 *
 * @str: filename for the executable program/code
 *
 * Return: nothing
*/
void __exit(char *str)
{
	printf("\n\tUsage: %s PID SEARCH_TEXT REPLACE_TEXT\n\n", str);
	exit(1);
}

/**
 * main - Entry point
 *
 * Description: this is a C program to replace the python code for this
 *              Hack The Virtual Memory task. I haven't learnt pyhon yet
 *              so I am using the C knowledge that I know to implement
 *              the python code, it will also be a learning opportunity
 *
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 (Success) | 1 if it fails
*/

int main(int argc, char *argv[])
{
	int pid, errnum;
	char maps_file[FILENAME_MAX];
	char mem_file[FILENAME_MAX];
	char line[LINE_MAX];
	char *search_string, *write_string;

	/*check usage*/
	if (argc != 4)
		__exit(argv[0]);

	pid = atoi(argv[1]); /*get pid from args*/
	search_string = argv[2]; /*get search string from args*/
	write_string = argv[3]; /*get replace string from args*/

	/*check if our arguments are empty or below zero*/
	if (pid <= 0 || search_string == NULL || write_string == NULL)
		__exit(argv[0]);

	printf("[+] maps: /proc/%d/maps\n", pid);
	printf("[+] maps: /proc/%d/mem\n", pid);

	sprintf(maps_file, "/proc/%d/maps", pid);/*get maps file*/
	FILE *maps = fopen(maps_file, "r"); /*read file*/

	if (maps == NULL)
	{
		printf("[ERROR] Can not open file %p\n", maps);
		fprintf(stderr, "        I/O error (%s)\n", strerror(errnum));
		exit(1);
	}

	char addr[ARRY_MAX], perm[ARRY_MAX], offset[ARRY_MAX];
	char device[ARRY_MAX], inode[ARRY_MAX], pathname[ARRY_MAX];

	/*read maps file line by line*/
	while (fgets(line, sizeof(line), maps))
	{
		/*get line that contains the string [heap]*/
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

	/*check for permissions*/
	if (perm[0] != 'r' || perm[1] != 'w')
	{
		printf("[*] %s does not have read/write permission\n", pathname);
		fclose(maps);
		exit(0);
	}

	int count = 0;
	char *temp = addr;
	unsigned long int start_addr, end_addr;

	/*get start and end of the heap in the virtual memory*/
	while (temp != NULL)
	{
		char *end = NULL;

		/*reset errno to zero before call*/
		errno = 0;

		start_addr = strtoul(addr, &end, 16);
		if (addr == end)
		{
			printf("[*] ERROR parsing of starting address of the heap [ %s ] address failed\n.", addr);
			fclose(maps);
			exit(1);
		}
		else if ((start_addr == LONG_MAX || start_addr == LONG_MIN) && errno == ERANGE)
		{
			printf("[*] ERROR out of range while parsing for starting address from heap address: %s\n", addr);
			fclose(maps);
			exit(1);
		}
		else
		{
			char *end2 = NULL;

			if (*end == '-')
				end++;

			end_addr = strtoul(end, &end2, 16);
			if (end == end2)
			{
				 printf("[*] ERROR parsing of ending address of the heap [ %s ] address failed\n.", addr);
				 fclose(maps);
				 exit(1);
			}
			else if ((end_addr == LONG_MAX || end_addr == LONG_MIN) && errno == ERANGE)
			{
				printf("[*] ERROR out of range while parsing for starting address from heap address: %s\n", addr);
				fclose(maps);
				exit(1);
			}
			else if (*end2 != '\0') /*never trust your os*/
			{
				printf("[*] Wrong address format\n");
				fclose(maps);
				exit(1);
			}
			else
				temp = NULL;
		}
		printf("\tAddr start [%lx] | end [%lx]\n", start_addr, end_addr);
	}

	sprintf(mem_file, "/proc/%d/mem", pid); /*get mem file*/
	FILE *mem = fopen(mem_file, "r"); /*read file*/

	/*read heap*/

	return (0);
}
