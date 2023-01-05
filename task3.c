#include <stdio.h>
#include <ctype.h>

#define MAX_LETTERS 26

int main()
{

	FILE *text = fopen("text.txt", "r");

	if (text == NULL)
	{
		printf("Error opening file");
		return 0;
	}

	int counts[26] = {0};

	int c;
	while ((c = fgetc(text)) != EOF)
	{
		if (isalpha(c))
		{
			counts[tolower(c) - 'a']++;
		}
		else
		{
			printf("Error. File contains non-alphabetic characters");
			return 0;
		}
	}

	fclose(text);

	for (int i = 0; i < 26; i++)
	{
		for (int j = i + 1; j < 26; j++)
		{
			if (counts[i] < counts[j])
			{
				int temp = counts[i];
				counts[i] = counts[j];
				counts[j] = temp;
			}
		}
	}

	printf("\nThe 8 most common letters are:\n");
	for (int i = 0; i < 8; i++)
	{
		printf("\n%c: %d\n", 'a' + i, counts[i]);
	}

	return 0;
}