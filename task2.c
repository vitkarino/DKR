#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>

#define N 3

void find_largest_below_main_diagonal(int matrix[N][N]);

int main() {

	int matrix[N][N];
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("\n\tEnter element [%d][%d]: ", i, j);
			scanf_s("%d", &matrix[i][j]);
		}
	}

	find_largest_below_main_diagonal(matrix);

	return 0;
}

void find_largest_below_main_diagonal(int matrix[N][N])
{
	int largest_value = matrix[0][0];
	int row = 0, col = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (matrix[i][j] > largest_value)
			{
				largest_value = matrix[i][j];
				row = i;
				col = j;
			}
		}
	}
	printf("\nLargest value below main diagonal: %d\n", largest_value);
	printf("\nIndex of the element: [%d][%d]\n", row, col);
}