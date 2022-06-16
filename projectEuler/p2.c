#include <stdio.h>

/**
 * main - Problem 2
 *
 * Description: Even Fibonacci Numbers
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int fib1, fib2, nextTerm, sum;
	fib1 = fib2 = nextTerm = 1;
	sum = 0;

	printf("Fibonacci Sequence: %d, ", fib1);

	while (nextTerm < 4000000)
	{
		nextTerm = fib1 + fib2;
		printf("%d", nextTerm);

		if (nextTerm % 2 == 0)
			sum += nextTerm;

		fib1 = fib2;
		fib2 = nextTerm;

		if (nextTerm > 4000000)
			printf("\n");
		else
			printf(", ");
	}

	printf("Sum of even-valued is %d\n", sum);
}
