#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int countUniquePaths(int i, int j, int rows, int cols, vector<vector<int>>& obstacleGrid) {
    if(i == rows-1 and j == cols-1) return 1;
    else if(dp[i][j] != -1) return dp[i][j];

    int ways1 = 0, ways2 = 0;
    if(i+1 < rows and obstacleGrid[i+1][j] == 0) ways1 += countUniquePaths(i+1,j,rows,cols,obstacleGrid);
    if(j+1 < cols and obstacleGrid[i][j+1] == 0) ways2 += countUniquePaths(i,j+1,rows,cols,obstacleGrid);

    return dp[i][j] = ways1+ways2;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(obstacleGrid[0][0] == 1) return 0;
    dp.clear();
    dp.resize(m, vector<int>(n,-1));

    int paths = countUniquePaths(0,0,m,n,obstacleGrid);
    return paths;
}

int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int uniqueWays = uniquePathsWithObstacles(obstacleGrid);

    cout << "Total Number of Unique Ways -> " << uniqueWays << endl;
}