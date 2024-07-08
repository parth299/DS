//Find the missing element in the sorted array with 1 to N elements

#include <iostream>
using namespace std;

int FindMissingElement(int *arr, int size){
    int start = 0, end = size - 1;
    int mid = start + (end - start)/2, ans;

    while(start<=end){
        if(arr[mid]-mid==1){
            continue;
        }
        else{
            ans = mid;
            break;
        }
    }
    return ans;

}

int main(){

    int arr[] = {1,2,3,4,5,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);   

    int Ans = FindMissingElement(arr, size);
    cout << "Missing element in the array is " << Ans << endl;

    return 0;
}