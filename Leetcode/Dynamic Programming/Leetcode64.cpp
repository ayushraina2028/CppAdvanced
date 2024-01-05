#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> dp;

long int f(int i, int j, int rows, int cols, vector<vector<int>>& grid) {
    if(i == rows-1 and j == cols-1) return grid[i][j];
    else if(i == rows or j == cols) return INT_MAX;
    else if(dp[i][j] != -1) return dp[i][j];

    int x = INT_MAX;
    long int cost = x;
    cost = grid[i][j] + min(f(i+1,j,rows,cols,grid),f(i,j+1,rows,cols,grid));

    return dp[i][j] = cost;
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    dp.clear();
    dp.resize(m, vector<int>(n,-1));

    int minCost = f(0,0,m,n,grid);

    return minCost;
}

int main() {
    vector<vector<int>> grid = {{1,2,3}, {4,5,6}};

    int minCost = minPathSum(grid);
    cout << minCost << endl;
}
