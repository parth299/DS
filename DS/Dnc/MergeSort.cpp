#include <iostream>
using namespace std;

void merge(int arr[], int start, int end, int mid){

    //calculate the length of the left and right array
    int lenLeft = mid - start + 1;
    int lenRight = end - mid;

    //Allocate the memory to new arrays
    int *leftArray = new int[lenLeft];
    int *rightArray = new int[lenRight];

    //copy the values to the array
    int j = start;
    for(int i=0; i<lenLeft; i++){
        leftArray[i] = arr[j++];
    }
    int m = mid+1;
    for(int i=0; i<lenRight; i++){
        rightArray[i] = arr[m++];
    }
    
    //now merge both the sorted arrays
    int mainArrayIndex = start;
    int left = 0, right = 0;
    while(left < lenLeft && right < lenRight){
        if(leftArray[left] > rightArray[right]){
            arr[mainArrayIndex++] = rightArray[right++];
        }
        else{
            arr[mainArrayIndex++] = leftArray[left++];
        }
    }

    //2 more cases where there might be some elements left due to one array being greater than the other
    while(left < lenLeft){
        arr[mainArrayIndex++] = leftArray[left++];
    }
    while(right < lenRight){
        arr[mainArrayIndex++] = rightArray[right++];
    }

    //deallocate the memory for sub-arrays
    delete[] leftArray;
    delete[] rightArray;

}

void mergeSort(int arr[], int start, int end){
    //Base case
    //single element - already sorted
    if(start == end){
        return ;
    }
    //starting index is always small - invalid array
    if(start > end){
        return ;
    }

    //Recursive case
    int mid = start + (end-start)/2;
    //recursive call for left sub-array
    mergeSort(arr, start, mid);
    //recursive call for right sub-array
    mergeSort(arr, mid+1, end);
    //merge the sub-arrays
    merge(arr, start, end, mid);
}

int main(){

    int arr[] = {23,44,21,56,74,88,94,100};
    int size = sizeof(arr)/sizeof(int);
    int start = 0, end = size-1;

    mergeSort(arr, start, end);

    cout << "Merge Sorted array : ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}