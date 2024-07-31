// VIEWS in tree

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* createTree() {
    cout << "Enter the data : ";
    int data;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(data);

    cout << "Enter the data for left of " << data << endl;
    root->left = createTree();

    cout << "Enter the data for right of " << data << endl;
    root->right = createTree();

    return root;
}

void leftView(TreeNode* root, vector<int> &ans, int level) {
    if(root == NULL) {
        return ;
    }

    if(level == ans.size()) {
        ans.push_back(root->data);
    }
    level++;
    leftView(root->left, ans, level);
    leftView(root->right, ans, level);
}

void rightView(TreeNode* root, vector<int> &ans, int level) {
    if(root == NULL) {
        return ;
    }

    if(level == ans.size()) {
        ans.push_back(root->data);
    }
    level++;
    leftView(root->right, ans, level);
    leftView(root->left, ans, level);
}

void levelOrderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(q.empty()) {
                break;
            } else {
                q.push(NULL);
            }
        }
        else {
            cout << front->data << "  ";
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

    TreeNode* root = createTree();

    vector<int> leftViewAns;
    leftView(root, leftViewAns, 0);

    vector<int> rightViewAns;
    rightView(root, rightViewAns, 0);

    levelOrderTraversal(root);

    cout << "Printing the left View" << endl;
    for(auto i: leftViewAns) {
        cout << i << " ";
    } 

    cout << "Printing the right View" << endl;
    for(auto i: rightViewAns) {
        cout << i << " ";
    } 

    return 0;
}