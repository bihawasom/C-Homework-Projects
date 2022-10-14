/*
Name: Bih Awasom
Section: 102
*/
#include <iostream>

using namespace std;

int main(){
    int testCase, rows, columns, r, fishRow, fishCol, bestRow, bestCol, indexRow, indexCol, mostFish;
    r = 0;
    fishRow = 0;
    fishCol = 0;
    bestRow = 0;
    bestCol = 0;
    indexRow = 0;
    indexCol = 0;
    mostFish = 0;

    cin >> testCase;

     while(r < testCase){
        cin >> rows >> columns;
    
        int **dataGrid;
        dataGrid = new int * [rows];
        for(int i = 0; i < rows; i++){
            dataGrid[i] = new int[columns];
        }

        for(int i=0; i < rows; i++){
            for(int j=0; j < columns; j++){
                cin >> dataGrid[i][j];
            }
        }

        //Rows
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                fishRow += dataGrid[i][j];
            }
            if(bestRow <= fishRow){
                bestRow = fishRow;
                indexRow = i;
            }
            fishRow = 0;
        }

        //Cols
        for (int j = 0; j < columns; j++) {
            for (int i = 0; i < rows; i++) {
                fishCol += dataGrid[i][j];
            }
            if(bestCol <= fishCol){
                bestCol = fishCol;
                indexCol = j;
            }
            fishCol = 0;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << dataGrid[i][j] << " ";
            }
            cout << endl;
        }

        mostFish = bestRow + bestCol;

        cout << "#" << r << ": at (" << indexRow << "," << indexCol << ") Bender catches " << mostFish << " fish." << endl;

        for(int i = 0; i < rows; i++){
            delete[] dataGrid[i];
        }
        delete[] dataGrid;

        bestCol = 0;
        bestRow = 0;
        indexCol = 0;
        indexRow = 0;
        mostFish = 0;
        r++;
    }
    
    return(0);
}

/* 
Plan:
one dynamite stick -> explodes vertically and horizontally, so all of the row (i) and column (j)
0. get number of test cases X
    cin >> testCase;
    while loop

1. inputs height and width of data grid X
    cin >> height >> width;

2. dynamically allocate array with height and width X
    int **dataGrid;
    dataGrid = new int * [height];
    for(int i = 0; i < height; i++){
        dataGrid[i] = new int[width];
    }

3. find where you can get the most fish
    search thru each column until you find max col, save what index it is
        int maxCol, fishCol = 0;
        for(int row=0; row< height; row++){
            for(int col=0; col < width; col++){
                fishCol = dataGrid[col][row] + fishCol;
                if(fishCol > maxCol){
                    maxCol = fishCol;
                }
            }  
            cout << "Max Column: " << maxCol << endl;
            fishCol = 0;
        }

    search thru each row until you find max row, save what index is
4. output #test case: at (i, j) Bender catches (# of fish) fish.

5. deallocate array  X
    for(int j = 0; j < width; j++){
        delete[] dataGrid[j];
    }
    delete[] dataGrid;

6. repeat from step 1-5 till test cases are over
*/

// ./a.out < sampleinput.txt -> types input
// ./a.out < sampleinput.txt > myoutput.txt -> keeps output 
// diff myoutput.txt sampleout.txt -> shows difference between output files