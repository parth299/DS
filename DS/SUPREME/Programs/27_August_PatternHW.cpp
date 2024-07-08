/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    //Numeric hollow inverted half pyramid
    // for(int row=0; row<n; row++){
    //     int num = row+1;
    //     for(int col=0; col<n-row; col++){
    //         if(row==0 || row==n-1){
    //             cout << num;
    //         }
    //         else if(col==0 || col==n-row-1){
    //             cout << num;
    //         }
    //         else{
    //             cout << " ";
    //         }
    //         num++;
    //     }
    //     cout <<endl;
    // }
    
    

    // Numeric palidrome equilateral pyramid
    // for(int row=0; row<n; row++){
    //     //Spaces
    //     int num = 1;
    //     for(int col=0; col<n-row-1; col++){
    //         cout<< "  ";
    //     }
    //     //numbers
    //     for(int col=0; col<=row; col++){
    //         cout<< num << " ";
    //         num++;
    //     }
    //     num--;
    //     //back numbers
    //     for(int c = num; c>0; ){
    //         c = c-1;
    //         if(c>0)
    //         cout<< c << " ";
    //     }
    //     cout << endl;
    // }
    
    
    
    //Solid half pyramid
    // if(n%2!=0){
    //     int up = n/2 + 1, low = n - up;
    //     for(int row=0; row<up; row++){
    //         for(int col=0; col<=row; col++){
    //             cout << "* ";
    //         }
    //         cout<<endl;
    //     }
    //     for(int row=0; row<low; row++){
    //         for(int col=0; col<low-row; col++){
    //             cout << "* ";
    //         }
    //         cout << endl;
    //     }
    // }
    // else{
    //     cout << "Cannot print-> Enter even number" <<endl;
    // }
    
    //Butterfly patern
    //Upper butterfly pattern
    // int num1 = n/2, num2 = n/2;
    // for(int row=0; row<num1; row++){
    //     //half pyramid 1
    //     for(int col=0; col<=row; col++){
    //         cout << "* ";
    //     }
    //     //Inverted half pyramid
    //     for(int col=0; col<2*num1-2*row-2; col++){
    //         cout << "  ";
    //     }
    //     //half pyramid 2
    //     for(int col=0; col<=row; col++){
    //         cout << "* ";
    //     }
    //     cout<<endl;
    // }
    // //Lower butterfly
    // for(int row=0; row<num2; row++){
    //     //half pyramid 1
    //     for(int col=0; col<num2-row; col++){
    //         cout << "* ";
    //     }
    //     //Inverted half pyramid
    //     for(int col=0; col<2*num2+2*row-8; col++){
    //         cout << "  ";
    //     }
    //     //half pyramid 2
    //     for(int col=0; col<num2-row; col++){
    //         cout << "* ";
    //     }
    //     cout<<endl;
    // }
    
    //floy's triangle
    // for(int row=0; row<n; row++){
    //     static int n = 1;
    //     for(int col=0; col<=row; col++){
    //         if(row==0 || row==1 || row==2 || row==3){
    //             cout << n++ << "     ";
    //         }
    //         else{
    //             cout << n++ << "    ";
    //         }
    //     }
    //     cout << endl;
    // }
    

    return 0;
}
