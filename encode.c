#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Please invoke as %s <key> \n", argv[0]);
		return 1;
	}

	char *key = argv[1];
	int key_len = strlen(argv[1]);
	int i = 0;

	int c = 0;
	for (i = 0; i < key_len; i++)
	{
		c += *(key + i);
	}

	int nextChar = getchar();
	while (nextChar != EOF)
	{
		if (nextChar == ' ')
		{
			putchar(' ');
			nextChar = getchar();
			continue;
		}
		else if (nextChar == '\n')
		{
			putchar('\n');
			nextChar = getchar();
			continue;
		}
		else if (nextChar == '\t')
		{
			putchar('\t');
			nextChar = getchar();
			continue;
		}
		if (isdigit(nextChar))
		{
			int output = (nextChar + c - '0') % 10 + '0';
			putchar(output);
			nextChar = getchar();
			continue;
		}
		if (!isalpha(nextChar))
		{
			putchar('*');
			nextChar = getchar();
			continue;
		}

		// checking if the nextchar has an uppercase letter
		if ((nextChar & 0b00100000) == 0)
		{
			int output = ((nextChar + c - 'A') % 26 + 'A');
			putchar(output);
		}
		else
		{
			int output = ((nextChar + c - 'a') % 26 + 'a');
			putchar(output);
		}
		nextChar = getchar();
	}
	return 0;
}
