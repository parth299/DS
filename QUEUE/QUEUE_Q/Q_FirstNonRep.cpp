#include <iostream>
#include <queue>
using namespace std;

int main() {

    string str = "aaacdecd";

    queue<char> q;
    int map[26] = {0};
    string ans;

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        map[ch - 'a']++;
        q.push(ch);
    }

    while(!q.empty()) {
        if(map[q.front() - 'a'] > 1) {
            q.pop();
        }
        else {
            ans = q.front();
            break;
        }
    }

    if(q.empty()) {
        ans = "#";
    }

    cout << "First non repeating character in string is : " << ans << endl;

    return 0;
}