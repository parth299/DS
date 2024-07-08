#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        int row;
        int col;

    Node(int val, int r, int c){
        data = val;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

vector<int> mergeSorted(int arr[][4], int k, int n){
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    vector<int> ans;
    for(int i=0; i<k; i++){
        Node* temp = new Node(arr[i][0], i, 0);
        minHeap.push(temp);
    }
    //Processing for first K elements done!

    //Process the leftover elements of all the arrays

    while(!minHeap.empty()){
        Node* mini = minHeap.top();
        //Got the minimum element;
        minHeap.pop(); //Removed the minimum element from the heap;

        ans.push_back(mini->data);

        if(mini->col + 1 < n){
            Node* newNode = new Node(arr[mini->row][mini->col+1], mini->row, mini->col+1);
            minHeap.push(newNode);
        }
    }

    return ans;
}

int main(){

    int arr[][4] = {
        {2,4,6,8},
        {3,5,7,9},
        {10,20,30,40}
    };
    int k = 3;
    int n = 4;

    vector<int> ans = mergeSorted(arr, k, n);

    cout << "Printing the array : ";
    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}