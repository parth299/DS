#include <iostream>
using namespace std;

class queue{

    public:
        int front, rear, size;
        int *arr;

        queue(int size){
            this->size = size;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

        void push(int data){
            //queue is full 
            if(rear == size){
                cout << "Queue is full! can't insert more elements" << endl;
                return ;
            }

            //you can insert the element
            arr[rear] = data;
            rear++;

        }

        void pop(){
            //check whether queue is empty or not
            if(front == rear){
                cout << "Queue is empty" << endl;
            }
            else{
                arr[front] = -1;
                front++;
                if(front == rear){
                    front = 0;
                    rear = 0;
                }
            }
        }

        int getSize(){
            return rear - front;
        }

};

int main(){

    queue q(5);

    q.push(10);
    q.push(20);
    // q.pop();
    cout << "Size of queue is " << q.getSize()<<endl;
    cout << "Front element is " << q.arr[q.front] << endl;
    return 0;
}