#include <stdio.h>
#include <string.h>

// Declare buildLPS so we can call it here
void buildLPS(char* pattern, int m, int lps[]);

void kmp(char* text, char* pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[1000];
    buildLPS(pattern, m, lps);

    int i = 0, j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m)
            {
                printf("Matched text: ");
                for (int k = i - m; k < i; k++)
                    printf("%c", text[k]);
                printf("\n");

                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}
