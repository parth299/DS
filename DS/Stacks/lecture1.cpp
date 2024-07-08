#include <iostream>
#include <stack>
using namespace std;

//Using STL and implementing the stack

int main(){

    stack<int> st;

    //adding elements using push
    st.push(7);
    st.push(10);
    st.push(30);
    st.push(40);
    cout<<"Lenght of the stack is "<< st.size() <<endl;

    cout<<"Element on the top is "<< st.top() <<endl;

    //removing elements using pop
    st.pop();
    cout<<"Now the top element after popping out one element is "<< st.top() <<endl;
    cout<<"Lenght of the stack is "<< st.size() <<endl;

    return 0;
}