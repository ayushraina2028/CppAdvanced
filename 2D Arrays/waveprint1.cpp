#include <iostream>
#include <vector>

using namespace std;

int main() {

    // waveprint 1 : 1 2 3 4 8 7 6 5 9 10 11 12 16 15 14 13
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    bool flag = true; // when true go right
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = 0;
    
    while(i < rows) {
        if(flag) {
            for(int j = 0;j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            i++;
            flag = false;
        }
        else {
            for(int j = cols-1;j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
            i++;
            flag = true;
        }
    }
}