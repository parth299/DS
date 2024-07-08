// Next Smaller element 
// arr -> [8,4,7,1,3]            ans -> [4,1,1,-1,-1]

// Approach 1 -> from left to right find the minimum element for  each element O(N²).      
// [(n-1)*(n-2)*(n-3)*...] comparisons

// Approach 2 -> from right to left, use stack to track the elements in O(N)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

    stack<int> st;
    vector<int> ans;
    cout << "INPUT  -> ";
    int arr[7] = {9,5,1,7,4,8,4};
    for(int i=0; i<7; i++) {
        cout << arr[i] << "   "; 
    } cout << endl;

    st.push(-1);

    for(int i=6; i>=0; i--) {
        if(arr[i] > st.top()) {
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        else {
            while(arr[i] < st.top()) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(arr[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    cout << "OUTPUT -> ";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << "   ";
    }
    cout << endl;

    return 0;
}


// example 2: arr[9,5,1,7,4,8,4]    ans[5,1,-1,4,4,4,-1]