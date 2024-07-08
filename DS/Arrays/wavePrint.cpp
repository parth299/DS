/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void wavePrint(vector<vector<int> > v){
    
    int row = v.size();
    int col = v[0].size();
    
    cout << "Printing the matrix in WAVE form ....." << endl;
    
    for(int startCol = 0; startCol<col; startCol++){
        //if col is even then print top to bottom
        if((startCol & 1) == 0){
            for(int startRow = 0; startRow<row; startRow++){
                cout << v[startRow][startCol] << " ";
            }
            cout << endl;
        }
        else {
            //if col is odd print from botton to top
            for(int endRow = row-1; endRow>=0; endRow--){
                cout << v[endRow][startCol] << " ";
            }
            cout << endl;
        }
    }
    
}

int main()
{
    vector<vector<int> > v = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    
    wavePrint(v);

    return 0;
}
