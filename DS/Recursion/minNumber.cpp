#include <iostream>
#include <limits>
using namespace std;

void findMin(int *arr, int size, int index, int& mini){
    if(index == size){
        return ;
    }
    mini = min(mini, arr[index]);

    //Recursive call
    findMin(arr, 5, index+1, mini);
}

void findMax(int *arr, int size, int index, int& maxi){
    if(index == size){
        return ;
    }
    maxi = max(maxi, arr[index]);

    //recursive call
    findMax(arr, size, index+1, maxi);
}

int main(){

    //Find the minimum number present in the array using recursion

    int arr[5] = {34,22,87,293,1111};
    int maxi = INT_MIN;
    int mini = INT_MAX;
    findMin(arr, 5, 0, mini);
    findMax(arr, 5, 0, maxi);

    cout << "Minimum number in array is : " << mini << endl;
    cout << "Maximum number in array is : " << maxi << endl;

    return 0;
}