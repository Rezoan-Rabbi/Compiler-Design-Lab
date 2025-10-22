#include <iostream>
using namespace std;

bool is_comment_line(string s){
    bool single_comment = false;
    int single_index, mul_starting, mul_ending;
    bool start_comment = false;
    bool Multiple_line_comment = false;

    for(int i = 0; i < s.size()-1; i++){
        if(s[i] =='/' && s[i+1] == '/'){
            single_comment = true;
            single_index = i+2;
        }
        if(s[i] == '/' && s[i+1] == '*'){
            start_comment = true;
            mul_starting = i+2;
        }
        else if(s[i] == '*' && s[i+1] == '/' && start_comment){
            Multiple_line_comment = true;
            mul_ending = i-1;
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

    if(!single_comment && !Multiple_line_comment){
        cout<<"There is no comment line\n";
        return false;
    }
}

int main(){
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    is_comment_line(s);
    return 0;
}
