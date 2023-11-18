#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int solve(vector<vector<int>>& matrix, int i, int j) {
    
}

int main() {
    vector<vector<int>> matrix = {{1,0,1,0,0}, {1,0,1,1,1}, {1,1,1,1,1}, {1,0,0,0,0}};
    int maxArea = solve(matrix, 0, 0);
    cout << maxArea << endl;
}