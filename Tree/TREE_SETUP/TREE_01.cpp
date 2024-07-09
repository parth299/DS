// Binary Trees: Trees are non linear (hierarichal) data structures.
// Traversal of Trees using 3 methods-> inorder, preorder, postorder.

// All 3 traversals consume space on the stack
// Space and time complexity of all three traversals is O(N);
// Morris Traversal is the way which can traverse in O(1);

// Last comes the level order traversal (a breadth first search) in which tree is traversed through each levels from left to right (using QUEUE);

#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
    public: 
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int value) {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* createBinaryTree() {
    cout << "Enter the value : ";
    int data;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(data);

    cout << "Enter the data for left of node " << data << endl;
    root->left = createBinaryTree();

    cout << "Enter the data for right of node " << data << endl;
    root->right = createBinaryTree();

    return root;
}

void preorderTraversal(TreeNode* & root) {
    if(root == NULL) {
        return ;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* & root) {
    if(root == NULL) {
        return ;
    }

    postorderTraversal(root->left);
    cout << root->data << " ";
    postorderTraversal(root->right);
}

void levelOrderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    cout << "Level Order Traversal" << endl;
    while(q.size() > 1) {

        TreeNode* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            q.push(NULL);
        }
        else {

            cout << front->data << " ";

            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }

    }
}

int main() {

    TreeNode* root = createBinaryTree();

    preorderTraversal(root);
    levelOrderTraversal(root);

    return 0;
}