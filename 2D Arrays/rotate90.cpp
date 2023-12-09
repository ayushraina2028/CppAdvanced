#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateMatrix2(vector<vector<int>> matrix) {

    cout << " rotated matrix inplace " << endl;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0;i < rows; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    cout << " transposed matrix: " << endl;
    for(auto row : matrix) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

void rotateMatrix1(vector<vector<int>> matrix) {
    cout << "rotated matrix by 90 degrees" << endl;

    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i = 0;i < rows;i++) {
        for(int j = cols-1; j >= 0; j--) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    //if you have to do inplace swaps then take transpose and reverse each row.
}

int main() {
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    cout << " original matrix: " << endl;
    for(auto row : matrix) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    rotateMatrix1(matrix);
    rotateMatrix2(matrix);

}