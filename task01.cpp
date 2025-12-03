#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream fileInput("sample.txt");
    ofstream fileOutput("output.txt");

    if (!fileInput) {
        cout << "Unable to open 'sample.txt'" << endl;
        return 1;
    }

    vector<string> tokenList;
    string line;

    // Read the file line by line
    while (getline(fileInput, line)) {
        string currentString = "";

        // Process each character in the line
        for (char ch : line) {
            if (isspace(ch)) {
                if (!currentString.empty()) {
                    tokenList.push_back(currentString);
                    currentString.clear();
                }
            }
            else if (isalnum(ch) || ch == '_') {
                currentString += ch;
            }
            else if (ch == '.' && !currentString.empty() && isdigit(currentString[0])) {
                currentString += ch;  // Support for floating-point numbers
            }
            else {
                if (!currentString.empty()) {
                    tokenList.push_back(currentString);
                    currentString.clear();
                }
                string symbol(1, ch);
                tokenList.push_back(symbol);
            }
        }

        if (!currentString.empty()) {
            tokenList.push_back(currentString);
        }
    }

    // Add your name and ID as tokens
    tokenList.push_back("rabbi");
    tokenList.push_back("22-48925-3");

    // Write tokens to console and output file
    cout << "Tokens:\n";
    fileOutput << "Tokens:\n";
    for (const auto& token : tokenList) {
        cout << token << endl;
        fileOutput << token << endl;
    }

    // Write symbol types to console and output file
    cout << "\nSymbols:\n";
    fileOutput << "\nSymbols:\n";

    for (const auto& token : tokenList) {
        if (token == "int" || token == "return" || token == "cout" || token == "main" || token == "if" || token == "else" || token == "while" || token == "for") {
            cout << token << " -> Keyword" << endl;
            fileOutput << token << " -> Keyword" << endl;
        }
        else if (isdigit(token[0])) {
            if (token.find('.') != string::npos) {
                cout << token << " -> Floating-point Number" << endl;
                fileOutput << token << " -> Floating-point Number" << endl;
            } else {
                cout << token << " -> Integer" << endl;
                fileOutput << token << " -> Integer" << endl;
            }
        }
        else if (token.size() == 1 && !isalnum(token[0])) {
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "=" || token == "<" || token == ">" || token == "!" || token == "&" || token == "|") {
                cout << token << " -> Operator" << endl;
                fileOutput << token << " -> Operator" << endl;
            }
            else if (token == ";" || token == "," || token == "(" || token == ")" || token == "{" || token == "}") {
                cout << token << " -> Delimiter" << endl;
                fileOutput << token << " -> Delimiter" << endl;
            }
            else {
                cout << token << " -> Symbol" << endl;
                fileOutput << token << " -> Symbol" << endl;
            }
        }
        else if (token == "rabbi") {
            cout << token << " -> Name" << endl;
            fileOutput << token << " -> Name" << endl;
        }
        else if (token == "22-48925-3") {
            cout << token << " -> ID" << endl;
            fileOutput << token << " -> ID" << endl;
        }
        else {
            cout << token << " -> Identifier" << endl;
            fileOutput << token << " -> Identifier" << endl;
        }
    }

    fileInput.close();
    fileOutput.close();

    return 0;
}
