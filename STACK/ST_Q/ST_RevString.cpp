// stacks can be used to reverse something really easily

#include <iostream>
#include <stack>
using namespace std;

int main() {

    string str = "Parth";
    stack<char> st;

    for(int i=0; i<str.length(); i++) {
        st.push(str[i]);
    }

    cout << "Reversed string -> ";
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}