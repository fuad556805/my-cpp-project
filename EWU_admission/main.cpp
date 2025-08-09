#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <cctype>
using namespace std;

// Updated keyword database with 50+ keywords
unordered_map<string, string> keywordResponses = {
    // Academic Keywords (25)
    {"admission", "The admission process at East West University requires:\n- Completed application form\n- SSC and HSC transcripts\n- 4 passport photos\n- National ID/Birth certificate copy\nApply online through our admission portal."},
    {"deadline", "Admission deadlines:\n- Fall Semester: August 31\n- Spring Semester: January 15\n*Confirm exact dates at www.ewubd.edu"},
    {"fee", "Tuition fees (2023):\n- Undergraduate: ~90,000 BDT/semester\n- Graduate: ~110,000 BDT/semester\n*Additional fees apply for labs/activities"},
    {"semester", "Academic calendar:\n- Fall: September to January\n- Spring: February to June\n*Summer terms available for some programs"},
    {"department", "Faculties:\n1. Science & Engineering\n2. Business & Economics\n3. Arts & Social Sciences\n4. Law"},
    {"gpa", "Minimum requirements:\n- Undergraduate: 2.5 GPA in HSC/equivalent\n- Graduate: 2.75 GPA in Bachelor's"},
    {"program", "EWU offers:\n- BSc/MSc/PhD programs\n- MBA/EMBA\n- Evening programs\n- Professional certifications"},
    {"scholarship", "Financial aid options:\n- Merit scholarships (25-100% waiver)\n- Need-based grants\n- Sports quotas\nDetails: www.ewubd.edu/financial-aid"},
    {"credit", "Credit transfer:\n- Max 50% of credits transferable\n- Requires course equivalence approval\nSubmit transcripts to registrar office"},
    {"transcript", "Transcript requests:\n- Apply online via registrar portal\n- Fee: 300 BDT/copy\n- Processing time: 3-5 working days"},
    {"course", "Browse courses:\n- Department-wise course catalogs\n- Prerequisite information\n- Syllabus details at www.ewubd.edu/academics"},
    {"faculty", "Faculty information:\n- Qualifications\n- Research areas\n- Office hours available on department websites"},
    {"library", "Central library:\n- 100,000+ books/journals\n- Online databases\n- 24/7 access during exams\n- Quiet study zones"},
    {"campus", "Main campus:\nA/2, Aftabnagar, Dhaka-1212\nFeatures:\n- Modern classrooms\n- Computer labs\n- Cafeteria\n- Sports complex"},
    {"calendar", "Academic calendar includes:\n- Class schedules\n- Exam periods\n- Holidays\n- Vacations\nDownload from www.ewubd.edu/calendar"},
    {"registration", "Course registration:\n- Online via student portal\n- During add/drop period\n- Advisor approval required for freshmen"},
    {"result", "Result publication:\n- Mid-term: Within 2 weeks\n- Final: Within 4 weeks\nCheck student portal for grades"},
    {"payment", "Fee payment options:\n1. bKash/Nagad (EWU-Admission)\n2. Bank deposit (Prime Bank Ltd)\n3. Credit card online"},
    {"international", "International students:\n- Equivalence certificate required\n- TOEFL/IELTS for English proficiency\n- Special visa assistance"},
    {"hostel", "Accommodation:\n- On-campus dormitory (limited)\n- Off-campus housing assistance\n- Contact: hostel@ewubd.edu"},
    {"transport", "Transport services:\n- Campus shuttles from key locations\n- Route details at security office\n- Student discount on public transport"},
    {"facility", "Campus facilities:\n- Medical center\n- Prayer rooms\n- Computer labs\n- Auditorium\n- Sports grounds"},
    {"transfer", "Credit transfer process:\n1. Submit previous transcripts\n2. Course equivalence review\n3. Department approval\n4. Registrar processing"},
    {"withdrawal", "Course withdrawal:\n- Deadline: Week 12\n- 'W' grade recorded\n- Financial refund per policy\nConsult academic advisor"},
    {"graduation", "Graduation requirements:\n- Complete all credits\n- Minimum 2.25 CGPA\n- Clear dues\n- Apply in final semester"},

    // Daily Conversation Keywords (25)
    {"hi", "Assalamu Alaikum! Welcome to EWU admission help. How can I assist you?"},
    {"hello", "Hello! Ask about EWU admissions, programs, or campus life."},
    {"how", "I'm doing well, shadhon! How can I help with EWU today?"},
    {"bye", "Allah Hafez! Contact admission@ewubd.edu for more queries."},
    {"thank", "You're welcome! Visit www.ewubd.edu for detailed information."},
    {"name", "I'm EWU Admission Bot. How can I help you today?"},
    {"help", "I can assist with:\n- Admission queries\n- Program details\n- Fee structure\n- Application process"},
    {"contact", "Reach us:\n📞 +880-2-9882308\n✉️ admission@ewubd.edu\n📍 A/2, Aftabnagar, Dhaka-1212"},
    {"website", "Official website:\nwww.ewubd.edu\nContains:\n- Online application\n- Faculty profiles\n- Academic resources"},
    {"morning", "Good morning! Ready to assist with EWU admission queries."},
    {"evening", "Good evening! Ask about EWU programs or admission process."},
    {"today", "Today is "},  // Date will be appended
    {"time", "Current time: "},  // Time will be appended
    {"sorry", "No problem! Please rephrase your question about EWU."},
    {"okay", "Alright! What else would you like to know about East West University?"},
    {"yes", "Please continue with your question about EWU admissions."},
    {"no", "How else may I assist you with East West University information?"},
    {"maybe", "Feel free to ask when you have specific questions about EWU."},
    {"please", "Sure, I'd be happy to help. What EWU information do you need?"},
    {"welcome", "You're welcome! For campus tours, call +880-2-9882308."},
    {"good", "That's good to hear! How can I assist with EWU admission?"},
    {"bad", "Sorry to hear that. How can I help with your EWU query?"},
    {"weather", "For campus weather updates, check our mobile app 'EWU Connect'."},
    {"later", "Sure! I'll be here when you have more EWU questions. Allah Hafez!"},
    {"ok", "Okay. What EWU program or department are you interested in?"}
};

// Levenshtein distance for spelling correction
int levenshteinDistance(const string &s1, const string &s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (tolower(s1[i-1]) == tolower(s2[j-1])) ? 0 : 1;
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + cost});
        }
    }
    return dp[m][n];
}

// Spelling correction with threshold
string correctSpelling(const string &input) {
    if (input.length() < 3) return input;

    string bestMatch = input;
    int minDist = INT_MAX;

    for (const auto &pair : keywordResponses) {
        int dist = levenshteinDistance(input, pair.first);
        if (dist < minDist) {
            minDist = dist;
            bestMatch = pair.first;
        }
    }

    return (minDist <= 2) ? bestMatch : input;
}

// KMP pattern matching utilities
vector<int> computeLPS(const string &pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

bool KMPsearch(const string &text, const string &pattern) {
    if (pattern.empty()) return false;

    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    int n = text.length(), m = pattern.length();

    while (i < n) {
        if (tolower(text[i]) == tolower(pattern[j])) {
            i++;
            j++;
            if (j == m) return true;
        } else {
            if (j) j = lps[j - 1];
            else i++;
        }
    }
    return false;
}

// Find best matching keyword with scoring
string findBestMatch(const string &input) {
    vector<pair<string, int>> matches;
    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    // Find all matches
    for (const auto &pair : keywordResponses) {
        if (KMPsearch(input, pair.first)) {
            int score = pair.first.length() - levenshteinDistance(lowerInput, pair.first);
            matches.push_back({pair.first, score});
        }
    }

    if (matches.empty()) return "";

    // Select best match by score then length
    sort(matches.begin(), matches.end(), [](const auto &a, const auto &b) {
        return (a.second != b.second) ? (a.second > b.second) : (a.first.length() > b.first.length());
    });

    return matches[0].first;
}

// Log conversation to file
void logConversation(const string &userInput, const string &response) {
    ofstream logfile("ewu_chatlog.txt", ios::app);
    if (!logfile) return;

    time_t now = time(0);
    char timestamp[100];
    strftime(timestamp, 100, "[%Y-%m-%d %H:%M:%S]", localtime(&now));

    logfile << timestamp << " User: " << userInput << "\n";
    logfile << timestamp << " Bot: " << response << "\n";
    logfile.close();
}

int main() {
    cout << "Bot: Welcome to East West University, Bangladesh. Type 'exit' to quit.\n\n";

    while (true) {
        cout << "You: ";
        string userInput;
        getline(cin, userInput);

        if (userInput == "exit") {
            cout << "Bot: Allah Hafez! Contact admission@ewubd.edu for further assistance.\n";
            break;
        }

        // Spelling correction
        string corrected = correctSpelling(userInput);
        if (corrected != userInput) {
            cout << "Bot: Did you mean: '" << corrected << "'? (y/n) ";
            char choice;
            cin >> choice;
            cin.ignore();
            if (tolower(choice) == 'y') userInput = corrected;
        }

        // Find best keyword match
        string bestKeyword = findBestMatch(userInput);
        string response;

        if (!bestKeyword.empty()) {
            response = keywordResponses[bestKeyword];

            // Handle special cases
            if (bestKeyword == "today") {
                time_t now = time(0);
                char date[100];
                strftime(date, 100, "%A, %B %d, %Y", localtime(&now));
                response += date;
            }
            else if (bestKeyword == "time") {
                time_t now = time(0);
                char t[100];
                strftime(t, 100, "%I:%M %p", localtime(&now));
                response += t;
            }
        } else {
            response = "I'm not sure about that. Ask about:\n";
            response += "- Admission process\n- Academic programs\n- Fees/scholarships\n";
            response += "Visit www.ewubd.edu or call +880-2-9882308";
        }

        cout << "Bot: " << response << endl;

        // Log conversation
        logConversation(userInput, response);
    }

    return 0;
}
