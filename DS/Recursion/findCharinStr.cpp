#include <iostream>
using namespace std;

void findOcc(string name, int size, int index, char target, vector<int>& ans){
    if(index == size){
        return ;
    }
    if(name[index] == target){
        ans.push_back(index);
    }

    //recursive call
    findOcc(name, size, index+1, target, ans);
}

int main(){

    //Given a string, print the target characteres present inside the string
    string name = "Parth Saini";
    vector<int> ans;
    char target = 'i';

    findOcc(name, name.length(), 0, target, ans);
    cout << "Printing the occurences of char a in the name : ";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}