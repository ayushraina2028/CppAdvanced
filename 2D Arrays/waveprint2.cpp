#include <iostream>
#include <vector>

using namespace std;

int main() {

    // waveprint 2 : 13 14 15 16 12 11 10 9 5 6 7 8 4 3 2 1
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    bool flag = true; // when true go right
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = rows-1;
    
    while(i >= 0) {
        if(flag) {
            for(int j = 0;j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            i--;
            flag = false;
        }
        else {
            for(int j = cols-1;j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
            i--;
            flag = true;
        }
    }
}