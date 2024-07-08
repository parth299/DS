#include <iostream>
using namespace std;

void doubleArr(int *arr, int size, int index){
    if(index == size){
        return ;
    }
    arr[index] = arr[index] * 2;
    doubleArr(arr, size, index+1);
}

int main(){

    //Double the values present in the array
    int arr[5] = {1,2,3,4,5};
    doubleArr(arr, 5, 0);

    cout << "Printing the array : ";
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}