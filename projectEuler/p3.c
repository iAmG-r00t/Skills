#include<stdio.h>

/**
 * main - Problem 3
 *
 * Description: Largest prime factor
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	long long num = 600851475143;
	int div = 2, maxPrime = 0;

	// loop through all prime factors both even and odd
	for (div = 2; num != 1; div += 2)
	{
		while (num % div == 0)
		{
			maxPrime = div;
			num /= div;
		}

		// when done looping on even prime number 2 increament by 1
		if (div == 2 && num % div != 0)
			++div;
	}

	if (maxPrime > 0)
		printf("Largest prime factor is %d\n", maxPrime);

	return (0);
}
