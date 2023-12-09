#include <iostream>
#include <vector>

using namespace std;

int main() {
    // inplace replacement only possible for square matrices
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    cout << " original matrix: " << endl;
    for(auto row : matrix) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    cout << " transposed matrix: " << endl;
    for(auto row : matrix) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

}