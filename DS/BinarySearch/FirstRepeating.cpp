#include <iostream>
#include <map>
using namespace std;

int findFirstOcc(int *arr, int size){
    int hash[100] = {0};
    for(int i=0; i<size; i++){
        hash[arr[i]]++;
    }
    for(int i=0; i<size; i++){
        if(hash[arr[i]] > 1){
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[] = {10,20,30,40,40,10,50,50,20};
    int size = sizeof(arr)/sizeof(int);

    int ans = findFirstOcc(arr, size);

    cout << "Ans is " << arr[ans] << endl;

    return 0;
}