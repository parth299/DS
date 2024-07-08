#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }

    int temp = st.top();
    cout << temp << endl;
    st.pop();
    printStack(st);
    st.push(temp);
}

void insertInSortedStack(stack<int> &st, int value) {
    if(st.empty()) {
        st.push(value);
        return;
    }
    if(st.top() <= value) {
        st.push(value);
        return;
    }

    int temp = st.top();
    st.pop();
    insertInSortedStack(st, value);
    st.push(temp);
}

int main() {

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Printing stack -> "<< endl;
    printStack(st);

    int value = 50;
    cout << "Inserting 25 in stack->" << endl;
    insertInSortedStack(st, value);

    cout << "Printing stack -> "<< endl;
    printStack(st);

    return 0;
}