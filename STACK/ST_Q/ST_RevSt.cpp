// Reverse a stack without using another stack

// input -> 10 20 30 40 50
// output -> 50 40 30 20 10 

#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> &st) {
    if(st.empty()) {
        return ;
    }
    int temp = st.top();
    cout << temp << endl;
    st.pop();
    printStack(st);
    st.push(temp);
}

void insertAtBottom(stack<int> &st, int value) {
    if(st.empty()) {
        st.push(value);
        return ;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, value);
    st.push(temp);
}

void reverseStack(stack<int> &st) {
    if(st.empty()){
        return;
    }

    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
}

int main() {

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Printing stack -> " <<endl;
    printStack(st);

    cout << "Reversing stack -> "<< endl;
    reverseStack(st);
    printStack(st);

    return 0;
}