#include <iostream>
#include <vector>

using namespace std;

int main() {

    // spiral -> 
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    bool flag = true; // when true go right
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int min_row = 0;
    int min_col = 0;

    int max_row = rows-1;
    int max_col = cols-1;

    while(min_row <= max_row && min_col <= max_col) {

        //  -> go right
        for(int i = min_col; i <= max_col; i++) {
            cout << matrix[min_row][i] << " ";
        }
        min_row++;

        // -> go dowm
        for(int i = min_row; i <= max_row; i++) {
            cout << matrix[i][max_col] << " ";
        }
        max_col--;

        // -> go left
        for(int i = max_col; i >= min_col; i--) {
            cout << matrix[max_row][i] << " ";
        }
        max_row--;


        // -> go up
        for(int i = max_row;i >= min_row; i--) {
            cout << matrix[i][min_col] << " ";
        }
        min_col++;
    } 
}