#include<iostream>
using namespace std;

bool is_Numeric(string s){
    for(int i = 0; i < s.size(); i++){
        if(!(s[i] <= '9' && s[i] >= '0')){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cout << "Enter input: ";
    cin >> s;

    if(is_Numeric(s)){
        cout << "Numeric Constant" << endl;
    }
    else{
        cout << "Not Numeric" << endl;
    }

    return 0;
}
