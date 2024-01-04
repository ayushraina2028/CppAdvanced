#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int uniquePaths(int i, int j, int rows, int cols) {
    if(i == rows-1 or j == cols-1) return 1;
    else if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = uniquePaths(i+1,j,rows,cols) + uniquePaths(i,j+1,rows,cols);
}

int main() {
    int m = 3, n = 7;

    dp.clear();
    dp.resize(m, vector<int>(n,-1));

    int paths = uniquePaths(0,0,m,n);
    cout << "Total Number of paths are -> " << paths << endl;
}