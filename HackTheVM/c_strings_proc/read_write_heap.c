#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * __exit - exits with usage option and exits
 *
 * @str: filename for the executable program/code
 *
 * Return: nothing
*/
void __exit(char *str)
{
	printf("Usage: %s PID SEARCH_TEXT REPLACE_TEXT\n", str);
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

  	sprintf(maps_file, "/proc/%d/maps", pid); /*get maps file*/
  	FILE* maps = fopen(maps_file, "r"); /*read file*/
	if (maps == NULL)
	{
		printf("[ERROR] Can not open file %p\n", maps);
		fprintf(stderr, "        I/O error (%s)\n", strerror( errnum ));
		exit(1);
	}

	sprintf(mem_file, "/proc/%d/mem", pid); /*get mem file*/
	FILE* mem = fopen(mem_file, "r"); /*read file*/

	return (0);
}
