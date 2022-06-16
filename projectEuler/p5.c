#include <stdio.h>


/**
 * main - Problem 5
 *
 * Description: Smallest multiple
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int i, num, smallest;
	smallest = 0;

	for (num = 1; num > 0; ++num)
	{
		for (i = 1; ((num % i == 0) && (i <= 20)); ++i)
		{
			if (i == 20)
			{
				smallest = num;
				break;
			}
		}

		if (smallest > 0)
			break;
	}

	printf("The smallest positive number that is evenly divisible by all the numbers from 1 to 20 is %d\n", smallest);

	return (0);
}
