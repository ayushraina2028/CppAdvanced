#include <iostream>
#include <vector>

using namespace std;

void transpose(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    cout << " transposed matrix: " << endl;
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9},{1,2,3}};

    cout << " original matrix: " << endl;
    for(auto row : matrix) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    transpose(matrix);

}