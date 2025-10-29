#include <iostream>
using namespace std;

bool isFirstCharValid(char ch) {
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch == '_')) {
        return true;
    }
    return false;
}

bool isOtherCharValid(char ch) {
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9') ||
        (ch == '_')) {
        return true;
    }
    return false;
}

bool isIdentifier(string word) {
    if (word.length() == 0) return false;

    if (!isFirstCharValid(word[0])) return false;

    for (int i = 1; i < word.length(); i++) {
        if (!isOtherCharValid(word[i])) return false;
    }

    return true;
}

int main() {
    string inputText;
    cout << "Enter a word to check: ";
    cin >> inputText;

    if (isIdentifier(inputText)) {
        cout << "It is a valid identifier." << endl;
    } else {
        cout << "It is not a valid identifier." << endl;
    }

    return 0;
}
