#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Step 1: Store keywords and responses
unordered_map<string, string> keywordResponses =
{
    {"admission", "The admission process requires submitting an online application with your academic documents."},
    {"date", "The admission dates are typically announced in November for the spring semester."},
    {"fee", "The tuition fee varies by department but averages around $5000 per semester."},
    {"semester", "EWU has two main semesters: Spring (January-June) and Fall (July-December)."},
    {"department", "EWU has departments in Engineering, Business, Arts, and Sciences."},
    {"gpa", "The minimum GPA requirement for admission is 2.5 for undergraduates and 3.0 for graduates."},
    {"hi", "Hello! How can I help you today?"},
    {"hello", "Hi there! What would you like to know about EWU?"},
    {"how", "I'm doing well, thank you! How about you?"},
    {"bye", "Goodbye! Have a great day!"},
    {"thank", "You're welcome! Let me know if you have other questions."},
    {"sorry", "No problem at all. How can I assist you?"}
};

// Step 2: Levenshtein distance for spelling correction
int levenshteinDistance(const string &s1, const string &s2)
{
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + cost});
        }
    }
    return dp[m][n];
}

string correctSpelling(const string &input)
{
    string corrected;
    int minDist = INT_MAX;

    for (const auto &pair : keywordResponses)
    {
        int dist = levenshteinDistance(input, pair.first);
        if (dist < minDist)
        {
            minDist = dist;
            corrected = pair.first;
        }
    }

    // Only correct if the distance is small (<= 2) and input isn't too short
    return (minDist <= 2 && input.length() > 2) ? corrected : input;
}

// Step 3: KMP algorithm for pattern matching
vector<int> computeLPS(const string &pattern)
{
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) len = lps[len-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMPsearch(const string &text, const string &pattern)
{
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    int n = text.length(), m = pattern.length();

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m) return true;
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
    return false;
}

// Step 4: Get response for matched keyword
string getResponse(const string &input)
{
    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    for (const auto &pair : keywordResponses)
    {
        if (KMPsearch(lowerInput, pair.first))
        {
            return pair.second;
        }
    }
    return "I'm not sure I understand. Could you ask about EWU admission, dates, fees, departments, or GPA requirements?";
}

int main()
{
    cout << "EWU Admission Bot: Hello! Ask me about admission process, dates, fees, departments, or GPA requirements.\n";

    while (true)
    {
        cout << "\nYou: ";
        string userInput;
        getline(cin, userInput);

        if (userInput == "exit")
        {
            cout << "EWU Admission Bot: Goodbye!\n";
            break;
        }

        // Correct spelling
        string corrected = correctSpelling(userInput);
        if (corrected != userInput)
        {
            cout << "Did you mean: " << corrected << "? (y/n) ";
            char confirm;
            cin >> confirm;
            cin.ignore();
            if (tolower(confirm) != 'y') corrected = userInput;
        }

        // Get and display response
        string response = getResponse(corrected);
        cout << "EWU Admission Bot: " << response << endl;
    }

    return 0;
}
