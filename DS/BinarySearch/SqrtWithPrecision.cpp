#include <iostream>
using namespace std;

double getSqrtWithPrecision(int num, int precision){

    double start = 0, end = num;
    double mid = start + (end - start)/(double)2, ans = -1;
    
    while(start<=end){
        
        if(mid*mid == num){
            ans = mid;
            break;
        }
        else if(mid*mid > num){
            end = mid - 1;
        }
        else {
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start)/2;
        double inc = 0.1;
        for(int i=0; i<precision; i++){
            while(ans*ans <= num){
                ans = ans + inc;
            }
            ans = ans - inc;
            inc = inc / 10;
        }
    }
    return ans;
}

int main(){

    int n = 8, precision = 6;
    cout << endl << "Finding the square root of " << n << " ....." << endl;
    
    double ans = getSqrtWithPrecision(n, precision);
    cout << "--->> " << ans << endl << endl;
 
    return 0;
}