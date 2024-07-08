// Reverse singly ll

#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
    
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

 void insertAtHead(Node* &head , Node* &tail, int value) {
        if(!head) {
            cout << "Cannot inset as ll is empty" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;

    }

    int getLength(Node* &head) {
        Node* temp = head;
        int count = 0;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void insertAtTail(Node* &head, Node* &tail, int value){
        if(!head) {
            cout << "Cannot inset as ll is empty" << endl;
            return;
        }

        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtPosition(Node* &head, Node* &tail, int value, int position){
        if(!head || !tail) {
            cout << "Cannot inset as ll is empty" << endl;
            return;
        }
        int len = getLength(head);

        if(position == 1){
            insertAtHead(head, tail, value);
        }
        else if(position == len) {
            insertAtTail(head, tail, value);
        }
        else {
            Node* temp = head;
            int i = 1;
            if(position > len) {
                cout << "cannot insert at that position" << endl;
                return;
            }
            while(i <= position-2) {
                temp = temp->next;
                i++;
            }

            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

void printLinkedList(Node* &head) {
    Node* temp = head;
    cout << "Linked List : ";
    while(temp != NULL ){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}

void deleteNode(Node* &head, Node* &tail, int position) {
    if(!head || !tail) {
        cout << "Linked list is empty" <<endl;
        return ;
    }
    int len = getLength(head);
    if(position == 1) {
        // Delete from head
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    else if(position == len) {
        //Delete from the last
        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete temp->next;
        tail = temp;
    }
    else {
        // delete from any position
        Node* prev= NULL;
        Node* curr = head;
        while(position != 1) {
            prev = curr;
            curr = curr->next;
            position--;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;


    }
}

void reverseLL(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

int main() {
    
    Node* head = new Node(10);
    Node* tail = head;

    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 8);
    insertAtTail(head, tail, 11);

    insertAtPosition(head, tail, 30, 3);
    // int length = getLength(head);
    // cout << length << endl;
    printLinkedList(head);

    // deleteNode(head, tail, 3);
    reverseLL(head);
    printLinkedList(head);

    return 0;

}
