#include <iostream>
#include <vector>
#include <climits>

using namespace std;
vector<vector<int>> dp;

int f(int i, int j, int rows, int cols, vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    
    if(i == rows) return 0;
    else if(dp[i][j] != -1) return dp[i][j];

    int cost = INT_MAX;
    for(int col_index = 0;col_index < cols; col_index++) {

        if(i < rows-1) cost = min(cost,grid[i][j] +moveCost[grid[i][j]][col_index] + f(i+1,col_index,rows,cols,grid,moveCost));
        else cost = grid[i][j];
    }

    return dp[i][j] = cost;
}

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size();
    int n = grid[0].size();


    dp.clear();
    dp.resize(m, vector<int>(n,-1));
    
    int minCost = INT_MAX;
    for(int i = 0;i < n; i++) {
        minCost = min(minCost, f(0,i,m,n,grid,moveCost));
    }
    

    return minCost;
}

int main() {
    vector<vector<int>> grid = {{5,1,2}, {4,0,3}};
    vector<vector<int>> moveCost = {{12,10,15}, {20,23,8}, {21,7,1}, {8,1,13}, {9,10,25}, {5,3,2}};

    int minCost = minPathCost(grid, moveCost);
    cout << minCost << endl;
}
