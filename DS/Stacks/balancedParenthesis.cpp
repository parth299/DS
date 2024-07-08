//WAP to check whether the parenthesis are matching the expression
// eg - ({}) is a balanced parenthesis..
#include <iostream>
#include <stack>
using namespace std;

bool checkBalanced(string s){
    vector<string> st;

    for(int i=0; s[i] != '\0'; i++){
        char ch = s[i];
        if()
    }
    
}

int main(){

    string s = "({()})";
    //check whether this string is balanced

    if(checkBalanced(s)){
        cout << "Parenthesis are balanced" << endl;
    }
    else{
        cout << "Parenthesis are not balanced" << endl;
    }

    return 0;
}