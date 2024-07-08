#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> arr;
    arr.push_back(50);
    arr.push_back(40);
    arr.push_back(30);

    arr.erase(arr.begin());
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}