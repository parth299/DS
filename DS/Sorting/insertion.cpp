#include <iostream>
using namespace std;

//INSERTION SORTING - in place sorting algorithm 
// time complexity --> O(n^2) for worst case and O(n) for best case.
// used when elements are small in number and input array is almost sorted.
void insertionSort(int *arr, int n){
    
    int i, j, key;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }

}

void printArray(int *arr, int n){
    cout<<"Array is : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[] = {4,83,9,2,27,66,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, size);
    printArray(arr, size);

    return 0;
}