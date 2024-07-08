#include <iostream>
#include <vector>
using namespace std;

int findMinDifference(vector<string>& timePoints) {
    int minDiff = INT_MAX;
        for(int index=0; index < timePoints.size(); index++){
            for(auto i: timePoints[index]){
                char ch = i;
                //convert hours into minutes
                int hours;
            }
        }
    return minDiff;
}
        

int main(){

    vector<string> timePoints = {"23:59","00:00"};
    int ans = findMinDifference(timePoints);
    cout << "Minimum time difference is " << ans << endl;

    return 0;
}