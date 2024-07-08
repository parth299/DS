#include <iostream>
#include <stack>
using namespace std;

string removeDuplicates(string s){
    stack<string> ans;
    int i = 0;
    while(i<s.length()){
        if(ans.empty()){
            ans.push(s[i]);
        }
        if(ans.top() != )
    }
}

int main(){

    string test_case = "abbaca";
    cout << "Answer is " << removeDuplicates(test_case);

    return 0;
}