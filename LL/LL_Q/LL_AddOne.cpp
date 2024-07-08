// Add one to the linkedlist

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

Node* reverseLL(Node* &prev, Node* &curr) {
    if(curr == NULL) {
        return prev;
    }

    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    return reverseLL(prev, curr);
}

void addOneLL(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* reversedHead = reverseLL(prev, curr);

    Node* temp = reversedHead;
    printLinkedList(temp);

    int carry = 1;
    while(temp != NULL) {
        int sum = temp->data + carry;
        int digit;
        if(sum > 9) {
            digit = sum % 10; // to be added
            temp->data = digit;
            carry = sum / 10;
        }
        else {
            temp->data = sum;
            carry = 0;
            break;
        }

        if(carry == 0){
            break;
        }
        temp = temp->next;
    }

    if(carry != 0 ){
        Node* newNode = new Node(carry);
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    prev = NULL;
    curr = reversedHead;
    reversedHead = reverseLL(prev, curr);

    head = reversedHead;

    // 9->9->9->NULL + 1->NULL
}

int main() {
    
    Node* head = new Node(9);
    Node* tail = head;

    insertAtHead(head, tail, 9);
    // insertAtHead(head, tail, 9);
    // insertAtTail(head, tail, 9);

    // insertAtPosition(head, tail, 30, 3);
    // int length = getLength(head);
    // cout << length << endl;
    printLinkedList(head);

    addOneLL(head);
    printLinkedList(head);

    return 0;

}
