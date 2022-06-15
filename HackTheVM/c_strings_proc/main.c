#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * main - uses strdup to create a new string, and prints
 *        the address of the new duplicated string
 *
 * Compile this way: gcc main.c -o loop
 *
 * Return: EXIT_FALIURE if malloc failed. Otherwise EXIT_SUCCESS
*/
int main(void)
{
	char *str;
	unsigned long int index = 0;
	int len;

	str = strdup("Holberton School");
	if (str == NULL)
	{
		fprintf(stderr, "Can't allocate mem with malloc\n");
		return (EXIT_FAILURE);
	}

	while (str)
	{
		len = strlen(str);
		printf("PID [%d] index [%lu]  string -> %s Length [%d] Address (%p)\n",getpid(), index, str, len, (void *)str);
		sleep(1);
		index++;
	}
	return (EXIT_SUCCESS);
}
