// PREVIOUS SMALLER ELEMENT 
// Input -> [8,5,1,9,4,6]   Output -> [-1,-1,-1,1,1,4]

// example 2.  Input -> [5,8,2,9,10,4,7]    Output -> [-1,5,-1,2,9,2,4]

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    stack<int> st;
    st.push(-1);

    vector<int> ans;

    int arr[7] = {5,8,2,9,10,4,7};
    cout << "Input -> ";
    for(int i=0; i<7; i++) {
        cout << arr[i] << "  ";
    } cout << endl;


    for(int i=0; i<7; i++) {
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

    cout << "Output ->  ";
    for(auto i: ans) {
        cout << i << "  ";
    }   cout << endl;

    return 0;
}