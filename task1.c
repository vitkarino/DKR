#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>

int main() {

	int N = 1;

	double sum = 0, a = 0;
	int sign = 1;

	printf("\nEnter N (N >= 1):");
	printf("\n\tN: ");
	scanf_s("%d", &N);

	printf("\nEnter a: ");
	scanf_s("%lf", &a);

	for (int i = 1; i <= N; i++)
	{
		sum += sign * a / (a + sign * i);
		sign *= -1;
	}

	sum += 1;
	printf("Sum = %lf", sum);

}