// REVERSE A QUEUE
// REVERSE FIRST K ELEMENTS IN A QUEUE

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q) {
    if(q.empty()) {
        return ;
    }

    int frontElement = q.front();
    q.pop();
    reverseQueue(q);

    q.push(frontElement);
}

void reverseKElements(queue<int> &q, int k) {
    stack<int> st;

    int i=0;
    while(i != k) {
        int frontElement = q.front();
        q.pop();

        st.push(frontElement);
        i++;
    }

    while(!st.empty()) {
        int element = st.top();
        st.pop();

        q.push(element);
    }

    int size = q.size();
    int elementsToBePlacedAtEnd = size - k;
    for(int i=0; i<elementsToBePlacedAtEnd; i++) {
        int frontElement = q.front();
        q.pop();
        q.push(frontElement);
    }
}

void printQueue(queue<int> q) {
    cout << "Printing queue : ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {

    queue<int> q;

    q.push(10);
    q.push(15);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    printQueue(q);

    // reverseQueue(q);
    reverseKElements(q, 5);

    printQueue(q);

    return 0;
}