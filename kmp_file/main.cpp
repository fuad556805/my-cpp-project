#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

void toLowerCase(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

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
    bool found = false;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m)
            {
                for (int k = i - m; k < i; k++)
                {
                    cout << text[k];
                }
                cout << endl;
                j = lps[j - 1];
                found = true;
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
    ifstream file("E:\\East West\\EWU documents\\summer 25\\Cse 302\\kmp.txt");

    if (!file)
    {
        cerr << "File couldn't be opened!" << endl;
        return 1;
    }

    string line, fullText = "";
    while (getline(file, line))
    {
        fullText += line;
    }
    file.close();

    char text[10000];
    strcpy(text, fullText.c_str());

    const int numPatterns = 4;
    char patterns[numPatterns][30] = { "mid", "quiz", "presentation", "lab exam" };

    cout<<"-----To-Do list-----"<<endl;
    for (int i = 0; i < numPatterns; i++)
    {
        kmp(text, patterns[i]);
    }

    return 0;
}
