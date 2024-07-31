// Construct Tree from Preorder and Inorder Traversals

//         10
//        /  \
//      20    30
//     / \    / \
//   40  50  60  70

// preorder -> [10,20,40,50,30,60,70];
// inorder  -> [40,20,50,10,60,30,70];

#include <iostream>
#include <queue>
using namespace std;

class Node {
    public: 
        int data;
        Node* left;
        Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int search(int inOrder[], int size, int element) {
    for(int i=0; i<size; i++) {
        if(inOrder[i] == element) {
            return i;
        }
    }
    return -1;
}

Node* createTreeFromInAndPreOrderTraversal(int preOrder[], int inOrder[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int size) {
    if(preOrderIndex >= size || inOrderStart > inOrderEnd) {
        return NULL;
    }

    int element = preOrder[preOrderIndex];
    preOrderIndex++;
    Node* root = new Node(element);

    int position = search(inOrder, size, element);

    root->left = createTreeFromInAndPreOrderTraversal(preOrder, inOrder, preOrderIndex, inOrderStart, position-1, size);

    root->right = createTreeFromInAndPreOrderTraversal(preOrder, inOrder, preOrderIndex, position+1, inOrderEnd, size);

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            if(q.empty()) {
                break;
            }
            else {
                cout << endl;
                q.push(NULL);
            }
        }
        else {
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
            cout << front->data << "  ";
        }
    }
}

int main() {

    int preOrder[] = {10,20,40,50,30,60,70};
    int inOrder[] = {40,20,50,10,60,30,70};
    int size = 7;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = size-1;

    Node* root = createTreeFromInAndPreOrderTraversal(preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);

    levelOrderTraversal(root);

    return 0;
}