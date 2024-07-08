// BST- Build and Traversal

#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

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

void topView(Node* root){
    map<int, int> hdToNode;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> front = q.front();
        Node* frontNode = front.first;
        int hd = front.second;
        q.pop();

        if(hdToNode.find(hd) == hdToNode.end()){
            hdToNode[hd] = frontNode->data;
            cout << frontNode->data << " ";
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    cout << "Printing the Top view for the tree : ";
    for(auto i: hdToNode){
        cout << i.second << " ";
    }
    cout << endl;
}

int main()
{
    Node* root = NULL;
    buildTree(root);

    levelOrderTraversal(root);
    topView(root);

    return 0;
}
