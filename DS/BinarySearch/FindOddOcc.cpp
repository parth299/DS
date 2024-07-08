#include <iostream>
using namespace std;

int findOddOcc(int *arr, int size){
    int start = 0, end = size - 1;
    int mid = start + (end - start)/2, ans = -1;
    
    while(start <= end){
        if(start == end){
            return start;
        }
        if(mid & 1){//odd case
            if(arr[mid] == arr[mid-1]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        else{
            //even index
            if(arr[mid] == arr[mid+1]){
                start = mid + 2;
            }
            else{
                end = mid;
            }
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){

    int arr[] = {50,50,10,10,30,30,50,50,20,20,90};
    int size = sizeof(arr)/sizeof(int);

    int answer = findOddOcc(arr, size);
    cout << "Ans is " << arr[answer] <<endl;

    return 0;
}