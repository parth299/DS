#include <iostream>
using namespace std;

void printNumDigits(int& num){
    int ans = num%10;
    if(num%10 == 0){
        return ;
    }
    num = num/10;
    printNumDigits(num);
    cout << ans << endl;
}

int main(){

    //Print the integer digits one by one
    int num = 4962;

    cout << "Printing the number ... " << endl;
    printNumDigits(num);

    return 0;
}