//Patterns

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    //Upper pyramid
    // for(int row = 0; row<n; row++){
    //         //spaces
    //         for(int col=0; col<n-row-1; col++){
    //             cout << " ";
    //         }
    //         //stars
    //         for(int col=0; col<row+1; col++){
    //             if(col==0 || col==row){
    //                 cout <<"* ";
    //             }
    //             else{
    //                 cout << "  ";
    //             }
    //         }
    //     cout << endl;
    // }
    
    // //lower pyramid
    // for(int row = 0; row<n; row++){
    //         //spaces
    //         for(int col=0; col<row; col++){
    //             cout << " ";
    //         }
    //         //stars
    //         for(int col=0; col<n-row; col++){
    //             if(col==0 || col==n-row-1){
    //                 cout <<"* ";
    //             }
    //             else{
    //                 cout << "  ";
    //             }
    //         }
    //     cout << endl;
    // }
    
    //Inverted half pyramid
    // for(int row=0; row<n; row++){
    //     int print = 1;
    //     for(int col=0; col<=row; col++){
    //         cout << col+1 << " ";
    //     }
    //     cout << endl;
    // }
    
    // //Patter 3(Hollow Diamond)
    //Upper part
    // for(int row=0; row<n; row++){
        
    //     //Inverted pyramid 1
    //     for(int col=0; col<n-row; col++){
    //         cout << "*";
    //     }
        
    //     //Full pyramid
    //     for(int col=0; col<2*row+1; col++){
    //         cout << " ";
    //     }
        
    //     //Inverted pyramid 2
    //     for(int col=0; col<n-row; col++){
    //         cout << "*";
    //     }
        
    //     cout << endl;
        
    // }
    // //Lower part
    // for(int row=0; row<n; row++){
        
    //     //Inverted pyramid 1
    //     for(int col=0; col<row+1; col++){
    //         cout << "*";
    //     }
        
    //     //Full pyramid
    //     for(int col=0; col<2*n-2*row-1; col++){
    //         cout << " ";
    //     }
        
    //     //Inverted pyramid 2
    //     for(int col=0; col<row+1; col++){
    //         cout << "*";
    //     }
        
    //     cout << endl;
        
    // }
    
    //Patter 4
    // for(int row=0; row<n; row++){
    //     for(int col=0; col<2*row+1; col++){
    //         if(col%2==0){
    //             cout << row+1;
    //         }
    //         else{
    //             cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }
    
    //Inverted half hollow pyramid
    // for(int row=0; row<n; row++){
    //     for(int col=0; col<n-row; col++){
    //         if(row==0 || row==n-1){
    //             cout << "* ";
    //         }
    //         else if(col==0 || col==n-row-1){
    //             cout << "* ";
    //         }
    //         else{
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }

    //Pattern 6 (ABC and then back to A pattern)
    // for(int row=0; row<n; row++){
    //     //first half
    //     char ch = 'A';
    //     for(int col=0; col<=row; col++){
    //         cout << ch++;
    //     }
    //     //second half
    //     for(char alphabet = ch-1; alphabet>='A'; ){
    //         alphabet = alphabet - 1;
    //         if(alphabet>='A')
    //             cout << alphabet;
    //     }
        
    //     cout << endl;
    // }

    return 0;
}
