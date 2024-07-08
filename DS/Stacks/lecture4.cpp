#include <iostream>
#include <stack>
using namespace std;

//Reversing a string using stack (Using STL)

int main(){

    string str = "Parth";

    stack<char> st;

    for(int i=0; str[i]!='\0'; i++){
        st.push(str[i]);
    }

    //Printing reversed string
    cout << "Reversed string is : ";
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
    return 0;
}