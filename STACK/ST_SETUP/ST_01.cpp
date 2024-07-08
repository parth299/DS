#include <iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;

    Stack(int totalSize) {
        arr = new int[totalSize];
        this->top = -1;
        this->size = totalSize;
    }

    void push(int data) {
        if(top == (size-1)){
            //Stack is full
            cout << "Stack overflow!" << endl;
            return;
        }
        else {
            //Stack has space, so push
            top++;
            arr[top] = data;
            cout << "Value inserted in stack -> " << data <<endl;
        }
    }

    void printSize(){
        cout << "No. of Elements in stack are -> "<< top+1 <<endl;
    }

    void pop() {
        if(top == -1) {
            cout << "Stack underflow!" <<endl;
            return;
        }
        else {
            // Stack has elements, can pop
            arr[top] = -1;
            top--;
            cout << "Stack top value popped!" <<endl;
        }
    }

    void printIsEmpty() {
        if(top == -1) {
            cout << "Stack is empty" <<endl;
        }
        else {
            cout << "Stack is not empty" << endl;
        }
    }

    int getTop() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }

};

int main() {

    Stack st(5);

    st.push(40);
    st.push(30);
    st.pop();
    st.pop();

    cout << "Topmost element is -> " << st.getTop() << endl;

    return 0;
}