#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//Merge K sorted Arrays 

// 1.) -> When we wanted to merge two sorted arrays, it was easy and could be implemented using two pointers, but for merging K sorted arrays, it is really difficult to manage so many pointers and always finding out the smallest among all those values.

// 2.) -> For this we can use heaps, since heap allows us to get the min element in the constant time, and moreover, its insertion and extraction takes time of O(Log n);

struct compare{
    bool operator()(int a, int b){
        //This syntax means that if a is greater than b, then a will have higher prority.
        return a > b;
    }
};

int main(){

    //Creates a max heap by default 
    // TO create min heap, provide a custom comparator function or use greater<int>;
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(10);
    pq.push(40);
    pq.push(90);
    pq.push(5);

    // cout << "Pq.top = " << pq.top() << endl;
    // cout << "Size :  " << pq.size() << endl;
    // cout << "Popping element"<< endl;
    // pq.pop();
    // cout << "New size : " << pq.size() << endl;
    // cout << "New top : " << pq.top() << endl;

    vector<int> data={20,300,50,1000,40};
    priority_queue<int, vector<int>, compare > p(data.begin(), data.end());

    cout << "Size : " << p.size() << endl;
    cout << "Top : " << p.top() << endl;

    return 0;
}