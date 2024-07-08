//Previous smaller element and next smaller element

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextSmallerElement(int arr[], int size){
    stack<int> st;
    vector<int> ans(size);
    st.push(-1);
    
    //Move from right to left
    for(int i=size-1; i>=0; i--){
        while(arr[i] <= st.top()){
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    // for(int i=0; i<size; i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    return ans;
}

vector<int> prevSmallerElement(int arr[], int size){
    stack<int> st;
    vector<int> ans(size);
    st.push(-1);
    
    for(int i=0; i<size; i++){
        while(arr[i] <= st.top()){
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    
    return ans;
}

void printArr(vector<int> arr, int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
//3 1 1 -1 2 -1 -1

int main()
{
    int arr[] = {8,3,6,1,7,2,9};
    int size = sizeof(arr)/sizeof(int);
    vector<int> ans = nextSmallerElement(arr, size);
    printArr(ans, size);
    
    vector<int> ans1 = prevSmallerElement(arr, size);
    printArr(ans1, size);
    
    return 0;
}
