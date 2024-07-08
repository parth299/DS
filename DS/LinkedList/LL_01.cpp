#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

void printLinkedList(Node* head){
    Node* temp = head;
    cout << "Linked List : " << endl;
    while(temp != NULL)  {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}

void insertAtHead(Node* &head, Node* &tail, int value) {
    // Linked List is empty
    if(head == NULL && tail == NULL) {
        //Create the node and point it to the head
        Node* newNode = new Node(value);
        head = newNode;
    }
    // Linked list is not empty
    else {
        //Create a new Node
        Node* newNode = new Node(value);
        //Point the next of newNode to the head;
        newNode->next = head;
        //Point the head to the newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int value){
    // Linked list is empty
    if(head == NULL && tail == NULL) {
        //Create the newNode and point head and tail to it
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    //Linked List is not empty
    else {
        //create the newNode 
        Node* newNode = new Node(value);
        //Get to the last of the LL where to insert
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        tail = newNode;
    }
}

int getLengthLL(Node* head){
    Node* temp = head;
    int len = 0;

    while(temp != nullptr) {
        len++;
        temp = temp->next;
    }

    return len;
}

void deleteNode(Node* &head, int position) {

    Node* temp = head;

    // If position is 1
    if(position == 1)  {
        Node* save = temp->next;
        free(temp);
        head = save;
        return;
    }
}

int main() {

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    Node* head = first;
    Node* tail = fourth;

    printLinkedList(head);
    cout << "Length of LL is : " << getLengthLL(head) << endl;

    // insertAtHead(head, tail, 50);
    // printLinkedList(head);
    // cout << "Length of LL is : " << getLengthLL(head) << endl;

    insertAtTail(head, tail, 100);
    printLinkedList(head);

    deleteNode(head,1);
    printLinkedList(head);
    cout << head->data << endl;


    return 0;
}