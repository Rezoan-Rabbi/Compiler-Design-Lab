#include <iostream>
using namespace std;
bool is_operator(char i){
    if(i == '+' || i == '-' || i == '*' || i == '/' || i == '%' || i == '='){
        return true;
    }
    return false;
}
int main()
{
    char i;
    cin>>i;
    if(is_operator(i)){
        cout<<"It is an Operator\n";
    }
    else{
        cout<<"Not an Operator\n";
    }
return 0;
}
