#include<stdio.h>

/**
 * main - Problem 4
 *
 * Description: Find the largest palindrome made from the
 * 	product of two 3-digit numbers.
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int a, b, temp, x, y;
	int prod, reverse, max;

	max = 0;

	for (a = 100; a <= 999; ++a)
	{
		for (b = 100; b <= 999; ++b)
		{
			prod = a * b;
			temp = prod;

			reverse = 0;

			while (temp != 0)
			{
				reverse = (reverse * 10) + (temp % 10);
				temp /= 10;
			}

			if (reverse == prod)
			{
				if (prod > max)
				{

					x = a;
					y = b;
					max = prod;
				}
			}
		}
	}

	printf("The largest palindrome made from the product of two 3-digit numbers is %d = %d * %d\n", max, x, y);

	return (0);
}
