#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> mat1 = {{1,2,3}, {4,5,6}};
    vector<vector<int>> mat2 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    cout << mat2[0].size() << endl;

    vector<vector<int>> answer(mat1.size(),vector<int> (mat2[0].size(),0));

    int rows = mat1.size();
    int cols = mat2[0].size();

    for(int i = 0;i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            for(int k = 0;k < mat1[0].size(); k++) {
                answer[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }

    for(auto row : answer) {
        for(auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}