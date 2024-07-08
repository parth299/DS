// 10
// 23
// 45 -> middle element(odd case)
// 24
// 67

// 10
// 20
// 30 -> middle element(even case)
// 40
// 50
// 60

#include <iostream>
#include <stack>
using namespace std;

int getMiddleElementFromStack(stack<int> &st, int position) {
    if(position == 1) {
        return st.top();
    }

    int temp = st.top();
    st.pop();
    position--;
    int ans = getMiddleElementFromStack(st, position);
    st.push(temp);
    return ans;
}

int main() {

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    //odd -> size/2 + 1
    //even -> size/2
    int position;
    if(st.size() %2 == 0){
        //even
        position = st.size()/2;
    }
    else {
        position = st.size()/2 + 1;
    }
    int ans = getMiddleElementFromStack(st, position);
    cout << "Middle element from stack -> " << ans << endl;

    return 0;
}
