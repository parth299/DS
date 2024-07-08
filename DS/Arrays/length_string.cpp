#include<iostream>
using namespace std;

int length(char str[]){
    int count = 0;
    for(int i=0; str[i]!='\0'; i++){
        count++;
    }
    return count;
}

int main(){
     
     char name[20];
     cout<<"Enter a string : "<<endl;
     cin>>name;
     cout<<"Length of the string is "<<length(name)<<endl;

}