// BST- Build and Traversal

#include <iostream>
#include <queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left = NULL;
        Node* right = NULL;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void buildTree(Node*& root){
    
    int data;
    cout << "Enter the data : ";
    cin >> data;
    
    if(data == -1){
        root = NULL;
        return ;
    }
    
    root = new Node(data);
    
    cout << "Enter the data for left of node " << data << " : " << endl;
    buildTree(root->left);
    
    cout << "Enter the data for the right of the node " << data << " : " << endl;
    buildTree(root->right);
}

void levelOrderTraversal(Node*& root){
    if(root == NULL){
        cout << "Tree is empty" << endl;
        return ;
    }
    queue<Node*> q;
    
    cout << "Printing the BST..." << endl;
    cout << " -> ";
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        
        q.pop();
        cout << temp->data << " ";
        
        if(temp->left){
            q.push(temp->left);
        }
        
        if(temp->right){
            q.push(temp->right);
        }
    }
    
}

int main()
{
    Node* root = NULL;
    buildTree(root);
    cout << root->data << endl;

    levelOrderTraversal(root);

    return 0;
}
