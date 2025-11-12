#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool isValidIdentifier(const string& word) {
    if (word.empty()) return false;

    if (!isalpha(word[0]) && word[0] != '_') return false;

    for (size_t i = 1; i < word.length(); i++) {
        if (!isalnum(word[i]) && word[i] != '_')
            return false;
    }

    return true;
}

int main() {
    // Example strings (you can modify or add more)
    string words[] = {
        "name", "_id", "1value", "data123", "user_name", "for", "helloWorld", "9abc", "_temp"
    };

    int n = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < n; i++) {
        if (isValidIdentifier(words[i])) {
            cout << words[i] << " is a valid identifier." << endl;
        } else {
            cout << words[i] << " is NOT a valid identifier." << endl;
        }
    }

    return 0;
}
