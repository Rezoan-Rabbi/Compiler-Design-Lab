#include <iostream>
#include <vector>
using namespace std;

// Task 1
bool is_Numeric(string s){
    for(int i = 0; i < s.size(); i++){
        if(!(s[i] <= '9' && s[i] >= '0')){
            return false;
        }
    }
    return true;
}

// Task 2
bool is_operator(char i){
    if(i == '+' || i == '-' || i == '*' || i == '/' || i == '%' || i == '='){
        return true;
    }
    return false;
}

// Task 3
bool is_comment_line(string s){
    bool single_comment = false;
    int single_index = 0, mul_starting = 0, mul_ending = 0;
    bool start_comment = false;
    bool Multiple_line_comment = false;

    for(int i = 0; i < s.size()-1; i++){
        if(s[i] =='/' && s[i+1] == '/'){
            single_comment = true;
            single_index = i+2;
            break;
        }
        if(s[i] == '/' && s[i+1] == '*'){
            start_comment = true;
            mul_starting = i+2;
        }
        else if(s[i] == '*' && s[i+1] == '/' && start_comment){
            Multiple_line_comment = true;
            mul_ending = i-1;
            break;
        }
    }

    if(single_comment){
        cout<<"There is a single line comment\n";
        cout<<"Comment: ";
        for(int i = single_index; i < s.size(); i++){
            cout<<s[i];
        }
        cout<<endl;
        return true;
    }

    if(Multiple_line_comment){
        cout<<"There is multiple line comment\n";
        cout<<"Comment: ";
        for(int i = mul_starting; i <= mul_ending; i++){
            cout<<s[i];
        }
        cout<<endl;
        return true;
    }

    cout<<"There is no comment line\n";
    return false;
}

// Task 4
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

// Task 5
double count_avg(){
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    vector<int> numbers(size);
    int sum = 0;

    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
        sum = sum + numbers[i];
    }

    float average = (float)sum / size;
    return average;
}

// Task 6
void find_min_max(){
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    vector<int> data(size);
    cout << "Enter " << size << " elements:" << endl;

    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    int minValue = data[0];
    int maxValue = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] < minValue) {
            minValue = data[i];
        }
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }

    cout << "Minimum value: " << minValue << endl;
    cout << "Maximum value: " << maxValue << endl;
}

int main(){
    cout << "Press 1 to Check Numeric." << endl;
    cout << "Press 2 to Check Operator." << endl;
    cout << "Press 3 to Check Comment Line." << endl;
    cout << "Press 4 to Check Identifier." << endl;
    cout << "Press 5 to find Average." << endl;
    cout << "Press 6 to find Minimum and Maximum." << endl;
    cout << "Press 7 to Concate Name." << endl;
    cout << "Press 0 to Exit!" << endl;

    while(true){
        cout << "Enter Key: ";
        int x;
        cin >> x;

        if(x == 0){
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        else if(x == 1){
            string s;
            cout << "Enter input: ";
            cin >> s;

            if(is_Numeric(s)){
                cout << "Numeric Constant" << endl;
            }
            else{
                cout << "Not Numeric" << endl;
            }
        }
        else if(x == 2){
            char i;
            cout << "Enter operator: ";
            cin >> i;
            if(is_operator(i)){
                cout << "It is an Operator" << endl;
            }
            else{
                cout << "Not an Operator" << endl;
            }
        }
        else if(x == 3){
            string s;
            cout << "Enter a string: ";
            cin.ignore();
            getline(cin, s);
            is_comment_line(s);
        }
        else if(x == 4){
            string inputText;
            cout << "Enter a word to check: ";
            cin >> inputText;

            if (isIdentifier(inputText)) {
                cout << "It is a valid identifier." << endl;
            } else {
                cout << "It is not a valid identifier." << endl;
            }
        }
        else if(x == 5){
            double average = count_avg();
            cout << "Average value: " << average << endl;
        }
        else if(x == 6){
            find_min_max();
        }
        else if(x == 7){

            string firstName, lastName, fullName;

            cout << "Enter your first name: ";
            cin >> firstName;

            cout << "Enter your last name: ";
            cin >> lastName;

            fullName = firstName + " " + lastName;

            cout << "Full name: " << fullName << endl;
        }
        else{
            cout << "Invalid option! Please try again." << endl;
        }
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
