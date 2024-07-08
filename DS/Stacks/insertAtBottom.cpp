//Stack :: Inserting the element in the bottom of the stack

#include <iostream>
#include <stack>

using namespace std;

void insertBottom(stack<int>& st, int toInsertAtBottom){
    
    //BASE CASE
    if(st.empty()){
        st.push(toInsertAtBottom);
        return ;
    }
    
    int temp = st.top();
    st.pop();
    insertBottom(st, toInsertAtBottom);
    
    st.push(temp);
    
}

int main()
{
    stack<int> st;
    int toInsertAtBottom;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    cout << "Enter the element to be inserted in the bottom : ";
    cin >> toInsertAtBottom;
    
    insertBottom(st, toInsertAtBottom);
   
    cout << "Printing the stack : ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}
