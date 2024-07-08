#include<iostream>
using namespace std;

class parth {
};

int pivot(int arr[],int size){
    int s, l, mid;
    s=0; l=size-1; mid=s+(l-s)/2;
    while(s<l){

        if(arr[mid]>arr[0]){
            s=mid;
        }
        else if(arr[mid]<arr[0]){
            l=mid;
        }
        mid = s + (l-s)/2;

    }
    return s;
}

int main(){

int arr[5]={5,6,1,2,3};
int result = pivot(arr,5);
cout<<"Pivot element is "<<result<<endl;

return 0;
}