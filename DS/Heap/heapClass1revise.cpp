#include <iostream>
using namespace std;

class Heap{
    public:
        int *arr;
        int capacity, size;
    Heap(int value){
        arr = new int[value];
        this->size = 0;
        this->capacity = value;
    }

    void insert(int value){
        if(size == capacity){
            cout << "Heap Overflow" << endl;
            return ;
        }

        //We can insert the value into the heap
        size++;
        int index = size;
        arr[index] = value;

        //Value is inserted - Check whether it is inserted at right place or not

        while(index > 1){
            int parentIndex = index/2;

            if(arr[parentIndex] > arr[index]){
                break;
            }
            else{
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
        }
    }

    int deleteFromHeap(){
        int answer = arr[1];

        arr[1] = arr[size];
        size--;
        int index = 1;
        //Item has been successfully deleted;

        //Now check whehter the element at the root is correctly placed
        while(index < size){
            int leftindex = 2*index;
            int rightIndex = 2*index + 1;

            int largestIndex = index;

            if(leftindex <= size && arr[largestIndex] < arr[leftindex]){
                largestIndex = leftindex;
            }
            if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
                largestIndex = rightIndex;
            }

            if(index == largestIndex){
                break;
            }
            else{
                swap(arr[largestIndex], arr[index]);
                index = largestIndex;
            }
        }

        return answer;
    }

    void printHeap(){
        cout << "Printing the heap : ";
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Heap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    h.insert(100);

    h.printHeap();

    h.deleteFromHeap();
    h.printHeap();

    return 0;
}