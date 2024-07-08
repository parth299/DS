#include <iostream>
using namespace std;

//Implementing two stacks in a single array

class stack{
    public:
        int *arr;
        int top1, top2;
        int size;


    stack(int size){
        arr = new int[size];
        this -> size = size;
        top1 = -1;
        top2 = size;  
    }

    //Basic opertions on stacks
    void push1(int data){
        if(top2 - top1 == 1){
            //cannot push element inside the stack
            cout << "Stack overflow" << endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data){
        if(top2 - top1 == 1){
            cout << "Stack overflow" << endl;
        } 
        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop1(){
        if(top1 == -1){
            cout << "Stack1 is empty" << endl;
        }
        else{
            arr[top1] = 0;
            top1--;
        }
    }
    void pop2(){
        if(top2 == size){
            cout << "Stack2 is empty" << endl;
        }
        else{
            arr[top2] = 0;
            top2++;
        }
    }

    void print(){
        cout << "Top1 : " << top1 <<endl;
        cout << "Top2 : " << top2 <<endl;
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){

    //Creating two stacks in single array --> It can be done by dividing the space of the entire array(BRUTE FORCE) or by pushing elements from 0th index for stack1 and last index for stack2(OPTIMIZED APPROACH)

    stack st(10);

    //Pushing elements in stack1
    st.push1(10);
    // st.print();
    st.push1(20);
    // st.print();
    st.push1(30);
    // st.print();
    st.push1(40);
    // st.print();
    st.push1(50);
    st.print();

    //Pushing elements in stack 2
    st.push2(100);
    // st.print();
    st.push2(110);
    // st.print();
    st.push2(120);
    st.push2(130);
    st.push2(140);
    st.print();
    st.push2(150);
    st.print();

    //popping elements from the stacks
    st.pop1();
    st.print();
    st.pop2();
    st.print();
    st.push2(150);
    st.print();
    st.push2(160);
    st.print();
    st.push2(7);
    

    return 0;
}