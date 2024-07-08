#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> & st, int value) {
    if(st.empty()) {
        st.push(value);
        return ;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, value);
    st.push(temp);
}

void printStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }

    int temp = st.top();
    st.pop();
    cout << temp << endl;
    printStack(st);
    st.push(temp);
}

int main() {

    stack<int> st;

    // old  new stack
    // 50   50
    // 40   40
    // 30   30
    // 20   20
    //      10

    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Printing stack -> " <<endl;
    printStack(st);

    insertAtBottom(st, 10);
    cout << "Printing stack -> " <<endl;
    printStack(st);

    return 0;
}