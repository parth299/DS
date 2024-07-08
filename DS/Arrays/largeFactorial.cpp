#include <iostream>
#include <vector>

using namespace std;

vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(1);
        int carry = 0;
        
        //loop interating over the numbers till the final factorial number
        for(int i=2; i<=N; i++){
            
            //inner loop iterating over each index of array
            
            for(int j = 0; j<ans.size(); j++){
                
                int productSum = ans[j]*i + carry;
                ans[j] = productSum % 10;
                carry = productSum / 10;
                  
            }
            while(carry){
                ans.push_back(carry % 10);
                carry /= 10;
            }
            carry = 0;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main(){

    vector<int> answer = factorial(10);
    cout << "Answer is ";
    for(int i=0; i<answer.size(); i++){
        cout << answer[i];
    }
    cout << endl;

    return 0;
}