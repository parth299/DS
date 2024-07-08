#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertInBst(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertInBst(root->right, data);
    }
    else{
        root->left = insertInBst(root->left, data);
    }

    return root;
}

void createBST(Node*& root){
    cout << "Enter the data : ";
    int data;
    cin >> data;

    while(data != -1){
        root = insertInBst(root, data);
        cout << "Enter data : ";
        cin >> data;
    }
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        cout << "Tree is empty" << endl;
        return ;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            //We need to print the data and insert the childs
            int value = frontNode->data;
            cout << value << " ";

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }
}

Node* bstFromInorder(int inOrder[], int start, int end){
    int mid = start + (end - start)/2;
    if(start>end){
        return NULL;
    }

    //Recursive case
    Node* root = new Node(inOrder[mid]);

    root->left = bstFromInorder(inOrder, start, mid-1);
    root->right = bstFromInorder(inOrder, mid+1, end);

    return root;
}

int main(){

    // Node* root = NULL;
    // createBST(root);

    // cout << "Printing level order traversal : ";
    // levelOrderTraversal(root);

    int inorder[] = {10,20,30,40,50,60,70};
    int size = sizeof(inorder)/sizeof(int);
    Node* root = bstFromInorder(inorder, 0, size-1);

    levelOrderTraversal(root);

    return 0;
}