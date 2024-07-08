#include <iostream>
using namespace std;

int findTarget(int *arr, int size, int index, int target){
    if(index == size){
        return -1;
    }
    if(arr[index] == target){
        return index;
    }

    //recursive call
    int finalAns = findTarget(arr, size, index+1, target);
    return finalAns;
}

int main(){

    //Find the target index in the array
    int arr[5] = {23,44,12,5,90};
    int target = 23;

    int ans = findTarget(arr, 5, 0, target);
    cout << "Target " << target << " is found at index no. " << ans << endl; 

    return 0;
}