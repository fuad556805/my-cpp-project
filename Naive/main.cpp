#include <iostream>
#include <string>
using namespace std;

// Naive string match function
bool isMatch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            return true; // Match found
    }
    return false;
}

int main() {
    string user_input;
    string bot_reply;

    cout << "User: ";
    getline(cin, user_input);

    // Convert input to lowercase
    for (char &c : user_input) c = tolower(c);

    if (isMatch(user_input, "hello"))
        bot_reply = "Hello, Boss!! How can I help you?";
    else
        bot_reply = "Sorry, I don't understand.";

    cout << "Bot: " << bot_reply << endl;

    return 0;
}
