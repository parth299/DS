#include <iostream>
using namespace std;


void insert(int *st, int &top, int size, int data){
    if(top == size-1){
        cout << "Stack is full - cannot insert" << endl;
    }
    else{
        //you can insert the element by incrementing the top and placing element
        top++;
        st[top] = data;
    }
}

void printStack(int *st, int size){
    cout << "Printing the stack .. : "; 
    for(int i=0; i<=size; i++){
        cout << st[i] << " ";
    }
    cout << endl;
}

void pop(int *st, int &top){
    if(top == -1){
        cout << "Stack is empty!" << endl;
    }
    else{
        //you can delete the element
        st[top] = 0;
        top--;
    }
}

int main(){
    int size = 10, top = -1;
    int st[size];

    //Inserting an element in the stack
    insert(st, top, size, 10);
    insert(st, top, size, 20);
    insert(st, top, size, 30);
    insert(st, top, size, 40);

    printStack(st, top);

    pop(st, top);

    printStack(st, top);

    return 0;
}