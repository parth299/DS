#include<iostream>
using namespace std;

char lower_case(char ch){
    return (ch - 'A' + 'a');
}

int main(){
    
    char ch;
    cout<<"enter the character : ";
    cin>>ch;
    cout<<"The character to lowercase is "<<lower_case(ch);

}