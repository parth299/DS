#include <iostream>

using namespace std;

class Queue {
    int* arr;
    int size;
    int front, rear;

    public:
        Queue(int size) {
            this->size = size;
            this->arr = new int[size];
            front = rear = -1;
        }
};

void push(int val) {
    if(this->rear == this->size) {
        cout << "Queue is full";
        return ;
    }
}

int main() {

    cout << "Queue setup ready" << endl;
    Queue q = new Queue(10);
    q.push(10);

    return 0;
}