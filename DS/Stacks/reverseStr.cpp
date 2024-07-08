#include <iostream>
#include <stack>
using namespace std;

int main(){

    string str = "ParthSaini";

    stack<char> st;

    for(char i : str){
        st.push(i);
    }

    cout << "Printing the reversed str : ";
    for(char i : str){
        cout << st.top();
        st.pop();
    }

    return 0;
}