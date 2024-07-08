#include <iostream>
using namespace std;

void fibonacci(int num, int f1, int f2){
    if(num == 0){
        return ;
    }
    int f = f1 + f2;
    cout << f << ", ";
    fibonacci(num-1, f2, f);
}

int main(){

    //Fibonacci series upto n
    int n;
    cout << "Enter the number upto which you want to print the fibonacci series : " << endl;
    cin >> n;

    cout << "Printing the fibonacci series : " << " 0, 1, ";
    fibonacci(n-2, 0, 1);

    return 0;
}