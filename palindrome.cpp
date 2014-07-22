#include <stdio.h>
#include <string.h>

char *arev = "A   3  HIL JM O   2TUVWXY5";
char *nrev = "1SE Z  8 ";

int is_palindrome(char *str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
			return 0;
	}

	return 1;
}

int is_mirrored(char *str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < (len + 1) / 2; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[len - i - 1] != arev[str[i] - 'A'])
				return 0;
		}
		else
		{
			if (str[len - i - 1] != nrev[str[i] - '1'])
				return 0;
		}
	}

	return 2;
}

int main()
{
	char str[21];
	while (scanf("%s", str) != EOF)
	{
		switch (is_palindrome(str) + is_mirrored(str))
		{
		case 1:
			printf("%s -- is a regular palindrome.\n\n", str);
			break;
		case 2:
			printf("%s -- is a mirrored string.\n\n", str);
			break;
		case 3:
			printf("%s -- is a mirrored palindrome.\n\n", str);
			break;
		default:
			printf("%s -- is not a palindrome.\n\n", str);
			break;
		}
	}

	return 0;
}