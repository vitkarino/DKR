#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>

int main()
{

	int N = 1;

	double sum = 0, a = 0;
	int sign = 1;

	do
	{
		printf("\nEnter N (N >= 1):");
		printf("\n\tN: ");
		scanf_s("%d", &N);

		if (N < 1)
		{
			printf("\nError. N must be >= 1\n");
		}
	
	} while (N < 1);

	printf("\nEnter a: ");
	printf("\n\ta: ");
	scanf_s("%lf", &a);

	for (int i = 1; i <= N; i++)
	{
		sum += sign * a / (a + sign * i);
		sign *= -1;
	}

	sum += 1;
	printf("\nSum = %lf", sum);

	return 0;
}