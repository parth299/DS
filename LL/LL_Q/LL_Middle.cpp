// Middle of ll

// It has two approaches 
// 1.
// even case -> depends on the question
// odd case -> always the centermost node

// 2. Tortoise approach(slow and fast pointer)
// slow pointer goes 1 step
// fast pointer goes 2 step 

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

int middleNode(Node* &head) {
    int len = getLength(head);
    int middle = (len/2) + 1;
    Node* temp = head;

    while(middle != 1) {
        middle--;
        temp = temp->next;
    }

    return temp->data;
}

Node* middleTortoise(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;

        }
    }

    return slow;
}

int main() {
    
    Node* head = new Node(10);
    Node* tail = head;

    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 8);
    insertAtTail(head, tail, 11);

    insertAtPosition(head, tail, 30, 3);
    insertAtPosition(head, tail, 40, 4);
    insertAtPosition(head, tail, 45, 5);

    printLinkedList(head);


    int middle = middleNode(head);
    cout << "Middle node is : " << middle << endl;
    Node* mid = NULL;
    mid = middleTortoise(head);
    cout << "middle node is : " <<mid->data << endl;

    return 0;

}