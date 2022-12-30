#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_FREQUENCY_LETTERS 8

void count_letter_frequencies(const char* filename, int* frequencies);
void find_most_frequent_letters(const int* frequencies, int* letters, int* frequencies_out);

int main()
{

	int frequencies[ALPHABET_SIZE] = { 0 };
	count_letter_frequencies("text.txt", frequencies);

	int max_frequency_letters[MAX_FREQUENCY_LETTERS] = { 0 };
	int max_frequencies[MAX_FREQUENCY_LETTERS] = { 0 };
	find_most_frequent_letters(frequencies, max_frequency_letters, max_frequencies);

	printf("Top %d most frequent letters:\n", MAX_FREQUENCY_LETTERS);
	for (int i = 0; i < MAX_FREQUENCY_LETTERS; i++)
	{
		char letter = 'a' + max_frequency_letters[i];
		int frequency = max_frequencies[i];
		printf("%c: %d\n", letter, frequency);
	}

	return 0;
}

void count_letter_frequencies(const char* filename, int* frequencies)
{

	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file\n");
		return;
	}
	int c;
	while ((c = fgetc(file)) != EOF)
	{
		if (isalpha(c))
		{
			c = tolower(c);
			frequencies[c - 'a']++;
		}
	}

	fclose(file);
}

void find_most_frequent_letters(const int* frequencies, int* letters, int* frequencies_out)
{
	for (int i = 0; i < MAX_FREQUENCY_LETTERS; i++)
	{
		int max_frequency = 0;
		int max_frequency_letter = -1;
	
		for (int j = 0; j < ALPHABET_SIZE; j++)
		{
			if (frequencies[j] > max_frequency)
			{
				max_frequency = frequencies[j];
				max_frequency_letter = j;
			}
		}

		if (max_frequency_letter != -1)
		{
			letters[i] = max_frequency_letter;
			frequencies_out[i] = max_frequency;
		}
	}
}


