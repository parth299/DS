#include <iostream>
using namespace std;

class stack{
    int* arr;
    int size;
    int top;
    public:
        stack(int size){
            arr = new int[size];
            top = -1;
            this->size = size;
        }

        int getTop(){
            return arr[top];
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            return false;
        }

        int getSize(){
            return top+1;
        }

        void push(int data){
            if(top == size-1){
                cout << "Cannot insert! :: Stack Overflow";
                return ;
            }
            //stack is empty :: can insert the data
            top++;
            arr[top] = data;
        }

        void pop(){
            if(top == -1){
                cout << "Cannot delete :: Stack Underflow";
                return ;
            }
            //can delete the element from the stack
            top--;
        }

};

int main(){

    stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Size of array is : " << st.getSize() << endl;

    cout << "Top element is " << st.getTop() << endl;
    // st.pop();

    // cout << "Size of array after popping one element " << st.getSize() << endl;
    // cout << "Top element is " << st.getTop() << endl;
    st.push(60);
    st.push(70);
    
    return 0;
}