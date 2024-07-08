#include <iostream>
#include <vector>
using namespace std;

void findEvens(int *arr, int size, vector<int>& ans, int index){
    if(index == size){
        return ;
    }
    if(arr[index] % 2 == 0){
        ans.push_back(arr[index]);
    }

    //recursive call
    findEvens(arr, size, ans, index+1);
    
}

int main(){

    //Find the even numbers present in an array
    int arr[10] = {34,12,34,22,35,65,44,90,55,89};
    vector<int> ans;
    
    findEvens(arr, 10, ans, 0);

    cout << "Printing the even numbers : ";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}