// Sort a stack -> hint:: insert in sorted stack

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
        return ;
    }
    if(st.top() <= value) {
        st.push(value);
        return ;
    }

    int temp = st.top();
    st.pop();
    insertInSortedStack(st, value);
    st.push(temp);
}

void sortStack(stack<int> &st) {
    if(st.empty()) {
        return ;
    }

    int temp = st.top();
    st.pop();
    sortStack(st);
    insertInSortedStack(st, temp)
}

int main() {

    stack<int> st;

    st.push(30);
    st.push(10);
    st.push(60);
    st.push(25);
    st.push(55);
    st.push(20);

    // input ->20      output->60
    //         55              55
    //         25              30
    //         60              25
    //         10              20  
    //         30              10

    cout << "Printing stack -> "<< endl;
    printStack(st);

    sortStack(st);

    cout << "Printing stack -> "<< endl;
    printStack(st);

    return 0;
}