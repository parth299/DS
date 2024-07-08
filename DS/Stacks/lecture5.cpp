#include <iostream>
#include <stack>
using namespace std;

//Finding middle element of Stack
//NOTE : YOU CANNOT CREATE A NEW STACK

void getMiddle(stack<int>& st, int size){

    //Base case
    if(st.size() == 0){
        cout << "Stack is empty" << endl;
        return ;
    }
    if(st.size() == size/2 + 1){
        cout << "Middle element is " << st.top() << endl;
        return ;
    }

    int temp = st.top();
    st.pop();

    //Recursive call
    getMiddle(st, size);

    //Backtracking
    st.push(temp);

}

int main(){

    stack<int> st;
      
    getMiddle(st, st.size());

    return 0;
}