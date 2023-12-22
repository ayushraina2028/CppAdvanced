#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numrows) {
    vector<vector<int>> pascal;
    int size = 1;

    if(numrows == 1) {
        pascal.push_back({1});
        return pascal;
    }
    else if(numrows == 2) {
        pascal.push_back({1});
        pascal.push_back({1,1});
        return pascal;
    }
    else {
        pascal.push_back({1});
        pascal.push_back({1,1});
    }

    
    for(int i = 2;i < numrows; i++) {

        vector<int> row = {1};
        for(int j = 1;j <= i; j++) {
            if(j == i) row.push_back(1);
            else {
                row.push_back(pascal[i-1][j] + pascal[i-1][j-1]);
            }
        }

        pascal.push_back(row);
    }

    return pascal;
}

int main() {
    int n = 7;
    vector<vector<int>> pascal = generate(n);

    for(auto row : pascal) {
        for(auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}