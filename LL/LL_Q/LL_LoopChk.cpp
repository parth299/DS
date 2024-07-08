// Check loop in ll
// Can be done using several ways ...

// type -> 
// check for loop 
// starting point of loop
// remove the loop

// check for loop
// using map 
// slow and fast pointer meet

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

bool checkLoop(Node* & head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) {
            return true;
        }
    }
    return false;
}

Node* findStartingNodeInLoop(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        if(fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        else {
            cout << "Loop is not present !" << endl;
            break;
        }
        if(fast == slow) {
            slow = head;
            break;
        }
    }
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void removeLoop(Node* & head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if(slow == fast){
            slow = head;
            break;
        }
    }

    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
}


int main() {
    
    Node* head = new Node(10);
    Node* tail = head;

    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 8);
    insertAtTail(head, tail, 11);

    insertAtPosition(head, tail, 30, 3);
    tail->next = head->next->next;
    // printLinkedList(head);

    cout << "Starting node in loop -> " << (findStartingNodeInLoop(head))->data << endl;
    cout << "Does linked list contain loop -> " << checkLoop(head) << endl;
    removeLoop(head);
    cout << "removing loop..." <<endl;
    cout << "Does linked list contain loop -> " << checkLoop(head) << endl;


    return 0;

}
