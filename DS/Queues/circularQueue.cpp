#include <iostream>
using namespace std;

class circularQueue{
    public:
        int front, rear, size;
        int *arr;

        circularQueue(int size){
            this -> size = size;
            arr= new int[size];
            front = -1;
            rear = -1;
        }

        void push(){
            //Queue is full
            if(front == 0 && rear == size){
                
            }
        }

        void pop(){

        }
};

int main(){

    

    return 0;
}