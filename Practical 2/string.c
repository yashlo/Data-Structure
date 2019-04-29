// C program to search and replace
// all occurrences of a word with
// other word.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to replace a string with another
// string
char replaceWord(const char *s, const char *oldW,const char *newW)
{
	char *result;
	int i, cnt = 0;
	int newWlen = strlen(newW);
	int oldWlen = strlen(oldW);

	// Counting the number of times old word
	// occur in the string
	for (i = 0; s[i] != '\0'; i++)
	{
		if (strstr(&s[i], oldW) == &s[i])
		{
			cnt++;

			// Jumping to index after the old word.
			i = i + oldWlen - 1;
		}
	}

	// Making new string of enough length
	result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

	i = 0;
	while (*s)
	{
		// compare the substring with the result
		if (strstr(s, oldW) == s)
		{
			strcpy(&result[i], newW);
			i += newWlen;
			s += oldWlen;
		}
		else
			result[i++] = *s++;
	}

	result[i] = '\0';
	printf("New String: %s\n", result);
	//return result;
}

// Driver Program
int main()
{
	char str[100],c[10],d[10];
	printf("Enter String : ");
    gets(str);
    //str=(char*)malloc((strlen(str))*sizeof(char));

    printf("Enter the find Word in the String : ");
    gets(c);
    //c=(char*)malloc((strlen(c))*sizeof(char));

    printf("Enter the Replace Word in the String : ");
    gets(d);
    //d=(char*)malloc((strlen(d))*sizeof(char));


	//char *result = NULL;

	// oldW string
	printf("Old string: %s\n", str);

	replaceWord(str, c, d);

	//free(result);
	return 0;
}
