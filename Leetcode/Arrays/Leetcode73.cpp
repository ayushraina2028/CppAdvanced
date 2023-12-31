#include <iostream>
#include <vector>
using namespace std;

int main() {
 
    vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};

    int rows = matrix.size();
    int cols = matrix[0].size();

    // save indexes
    vector<pair<int, int>> zeroidx;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 0) zeroidx.push_back({i,j});
        }
    }

    for(auto pair : zeroidx) {

        for(int j = 0; j < cols; j++) {
            matrix[pair.first][j] = 0;
        }

        for(int i = 0;i < rows; i++) {
            matrix[i][pair.second] = 0;
        }

    }

    for(auto row : matrix) {
        for(auto child : row) {
            cout << child << " ";
        }
        cout << endl;
    }
}