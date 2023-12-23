#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix) {

    int rows = matrix.size();
    int cols = rows;

    for(int i = 0;i < rows; i++) {
        for(int j = i; j < cols; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // now just reverse each row
    for(int i = 0; i < rows; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return;
}

int main() {
    vector<vector<int>> matrix= {{1,2,3}, {4,5,6}, {7,8,9}};
    rotate(matrix);

    for(auto row : matrix) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}