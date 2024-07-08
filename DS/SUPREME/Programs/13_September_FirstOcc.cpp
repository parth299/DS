#include <iostream>
using namespace std;

//Find the first occurenece of the number in a sorted array

int FirstOccBinarySearch(int *arr, int size, int target){
    int start = 0, end = size - 1, ans;
    int mid = start + (end - start)/2;
    
    while(start<=end){
        if(arr[mid] == target){
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int LastOccBinarySearch(int *arr, int size, int target){
    int start = 0, end = size - 1, ans;
    int mid = start + (end - start)/2;
    
    while(start<=end){
        if(arr[mid] == target){
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){

    int arr[] = {10,10,10,10,10,10,20};
    int target, size = sizeof(arr)/sizeof(arr[0]);   

    cout << "Enter the Element to search in the array : ";
    cin>>target;

    int FirstAns = FirstOccBinarySearch(arr, size, target);
    int LastAns = LastOccBinarySearch(arr, size, target);
    cout << "Total occurences of " << target << " are " << LastAns-FirstAns+1;

    return 0;
}