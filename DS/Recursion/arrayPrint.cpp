#include <iostream>
using namespace std;

void printArr(int *arr, int size, int index){
    if(index == size){
        return ;
    }
    cout << arr[index] << " ";
    printArr(arr, size, index+1);
}

int main(){

    //Printing the array using recursion
    int arr[5] = {1,2,3,4,5};

    cout << "Printing the array : ";
    printArr(arr, 5, 0);

    return 0;
}