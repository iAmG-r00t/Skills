#include <stdio.h>

/**
 * main - Problem 6
 *
 * Description: Sum square difference
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int square, sqSum, sum;
	square = sqSum = sum = 0;

	for (int num = 1; num <= 100; ++num)
	{
		/* find sum of squares*/
		square = num * num;
		sqSum += square;

		/*sum of the first 100 natural numbers*/
		sum += num;
	}

	printf("The square of the sum is %d and the sum of the squares is %d\n", (sum * sum), sqSum);
	printf("The difference is %d\n", ((sum * sum) - sqSum));

	return (0);
}
