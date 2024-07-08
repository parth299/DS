#include<iostream>
#include<algorithm>
using namespace std;

char* reverse(char str[], int len){
    int s, e;
    s = 0, e = len - 1;
    while(s<=e){
        swap(str[s++], str[e--]);
    }
    return str;
}

int length(char str[]){
    int count = 0;
    for(int i=0; str[i]!='\0'; i++){
        count++;
    }
    return count;
}

int main(){

    char str[20];
    cout<<"Enter a string : "<<endl;
    cin>>str;
    cout<<"The reversed string is "<<reverse(str,length(str))<<endl;

}