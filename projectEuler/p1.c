#include <stdio.h>

/**
 * main - Problem 1
 *
 * Description: Multiples of 3 or 5
 *
 * Return: Always 0 (Success)
*/

int main(void)
{

	int sum = 0;

	for (int i = 0; i < 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	printf("The sum of all the multiples of 3 or 5 below 1000 is %d\n", sum);

	return (0);
}
