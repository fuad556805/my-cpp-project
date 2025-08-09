#include <iostream>
#include <cstring>

using namespace std;

void buildLPS(char pattern[], int m, int lps[])
{
    lps[0] = 0;
    int len = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char text[], char pattern[])
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
                // ✅ Print matched substring
                cout << "Matched text: ";
                for (int k = i - m; k < i; k++)
                {
                    cout << text[k];
                }
                cout << endl;

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

int main()
{
    char text[] = "ababcabcabababd";
    char pattern[] = "ababd";

    kmp(text, pattern);

    return 0;
}
