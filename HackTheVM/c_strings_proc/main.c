#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * main - uses strdup to create a new string, and prints
 *        the address of the new duplicated string
 *
 * Return: EXIT_FALIURE if malloc failed. Otherwise EXIT_SUCCESS
*/
int main(void)
{
	char *str;
	unsigned long int index = 0;

	str = strdup("Holberton");
	if (str == NULL)
	{
		fprintf(stderr, "Can't allocate mem with malloc\n");
		return (EXIT_FAILURE);
	}

	while (str)
	{
		printf("index [%lu]  string -> %s  Address (%p)\n", index, str, (void *)str);
		sleep(1);
		index++;
	}
	return (EXIT_SUCCESS);
}
