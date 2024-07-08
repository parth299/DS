#include <iostream>
using namespace std;

int getAns(int *arr, int target, int size){
    int start = 0, end = size - 1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(mid-1 > 0 && arr[mid-1] == target){
            return mid-1;
        }
        if(arr[mid] == target){
            return mid;
        }
        if(mid+1<size && arr[mid+1] == target){
            return mid+1;
        }
        if(arr[mid] < target){
            start = mid + 2;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){

    int arr[] = {20,10,30,40,50,70};
    int target = 10;

    int ans = getAns(arr, target, 6);
    if(ans == -1){
        cout << "Element not found"<<endl;
        return 0;
    }
    cout << "Element found at index " << ans << endl;

    return 0;
}