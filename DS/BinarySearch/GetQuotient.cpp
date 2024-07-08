#include <iostream>
using namespace std;

int getQuotient(int divisor, int divident){
    double start = 0, end = divident, ans = -1;
    double mid = start + (end-start)/2;

    while(start<=end){
        if(mid*divisor == divident){
            ans = mid;
            break;
        }
        if(mid*divisor < divident){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;

    }
    return ans;
}

int main(){

    int divisor = 1, divident = 1;

    int ans = getQuotient(abs(divisor), abs(divident));
    cout << "Quotient is " << ans <<endl;

    return 0;
}