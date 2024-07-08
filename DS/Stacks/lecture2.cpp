#include <iostream>
using namespace std;

//Implementing the stack using arrays

class stack{

    public:
        int *arr; 
        int size;
        int top;

    stack(int size){
        arr = new int[size];
        this -> size = size;
        top = -1;
    }

    //Basic Functions to operate over stack
    void push(int data){
        if(top >= size-1){
            cout << "Stack Overflow! cannot insert element" << endl;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    void pop(){
        if(top == -1){
            //stack is empty
            cout << "Stack Underflow! cannot delete an element" << endl;
        }
        else{
            //stack is not empty
            top--;
        }
    }

    int getSize(){
        return (top + 1);
    }

    int getTop(){
        if(top == -1){
            cout << "Stack is empty" <<endl;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

};

int main(){

    //stack creation with size 10
    stack st(10); int top;
    
    //pushing elements into stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    //deleting elements from stack
    st.pop();

    //checking the top element in stack
    cout << "Top element present in stack is " << st.getTop() << endl;

    //Checking the size of the stack
    cout << "The size of the stack is " << st.getSize() << endl;

    st.pop();
    st.pop();
    st.pop();
    if(st.isEmpty()){
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }

    return 0;
}