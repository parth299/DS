#include <iostream>
#include <stack>
using namespace std;
//Using Recursion to sort a stack data structure
void sortStack(stack<int>& st, int target){

    //base case
    if(st.empty()){
        st.push(target);
        return ;
    }
    if(st.top() >= target){
        st.push(target);
        return;
    }

    //reucursive relation
    int top = st.top();
    st.pop();
    sortStack(st, top);
    st.push(top);

}

void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
    int x = s.top();
    s.pop(); 
    PrintStack(s);
 
    cout << x << " ";
    s.push(x);
}

int main(){

    stack<int> st;

    st.push(30);
    st.push(6);
    st.push(77);
    st.push(2);
    st.push(28);

    cout << "Printing stack : ..." << endl;
    PrintStack(st);

    sortStack(st,st.top());
    cout << "Printing stack after sorting : " << endl;
    PrintStack(st);

    return 0;
}