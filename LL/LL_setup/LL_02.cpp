// Doubly ll
// Insertion -> check if head is null -> if not null 
// Deletion -> isolate the node -> delete using 'delete' keyword

#include <iostream>
using namespace std;

class Node {
    public:    
        int data;
        Node* prev;
        Node* next;
    Node(int val) {
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

int getLength(Node* & head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void insertAtHead(Node* &head, Node* &tail, int value) {

    if(head == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int value) {
    if(head == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtMid(Node* &head, Node* &tail, int position, int value) {
    if(head == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* prev = NULL;
        Node* curr = head;

        while(position != 1) {
            prev = curr;
            curr = curr->next;
            position--;
        }

        Node* newNode = new Node(value);
        newNode->prev = prev;
        prev->next = newNode;
        newNode->next = curr;
        curr->prev = newNode;
    }
}

void deleteNode(Node* &head, Node* &tail, int position) {
    if(!head) {
        cout << "cannot delete as dll is empty" << endl;
        return;
    }

    int len = getLength(head);
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if(position == len) {
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
    }
    else {
        // Node is somewhere between
        Node* prev = NULL;
        Node* curr = head;

        while(position != 1) {
            prev = curr;
            curr = curr->next;
            position--;
        }

        Node* temp = curr;
        prev->next = curr->next;
        curr->next->prev = prev;
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
}

void printDll(Node* &head) {
    Node* temp = head;
    cout << "Dll : ";
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }cout << "Null" <<endl;
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    // insertAtHead(head, tail, 40);
    // insertAtHead(head, tail, 30);
    // insertAtHead(head, tail, 20);
    // insertAtHead(head, tail, 10);

    printDll(head);

    insertAtTail(head, tail, 25);
    insertAtTail(head, tail, 10);
    insertAtHead(head, tail, 30);
    insertAtMid(head, tail, 3, 15);
    printDll(head);

    deleteNode(head, tail, 2);
    printDll(head);

    return 0;
}