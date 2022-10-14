/*
Name: Bih Awasom
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
