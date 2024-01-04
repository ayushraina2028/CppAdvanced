#include <iostream>
#include <vector>

using namespace std;

// Leetcode Hard
int countUniquePaths(int i, int j, int rows, int cols, vector<vector<int>>& grid,int count,int& zeroes) {
    if(grid[i][j] == 2 and count == zeroes) return 1;
    else if(i == rows or i == -1 or j == cols or j == -1 or (grid[i][j] == 2 and count != zeroes)) return 0;


    // mark visited
    grid[i][j] = 3;

    int ways_down = 0, ways_right = 0, ways_up = 0, ways_left = 0;

    if(i+1 < rows and (grid[i+1][j] == 0 or grid[i+1][j] == 2)) ways_down += countUniquePaths(i+1,j,rows,cols,grid,count+1,zeroes);
    if(j+1 < cols and (grid[i][j+1] == 0 or grid[i][j+1] == 2)) ways_right += countUniquePaths(i,j+1,rows,cols,grid,count+1,zeroes);
    if(i-1 >= 0 and (grid[i-1][j] == 0 or grid[i-1][j] == 2)) ways_up += countUniquePaths(i-1,j,rows,cols,grid,count+1,zeroes);
    if(j-1 >= 0 and (grid[i][j-1] == 0 or grid[i][j-1] == 2)) ways_left += countUniquePaths(i,j-1,rows,cols,grid,count+1,zeroes);


    grid[i][j] = 0;

    return ways_down + ways_up + ways_left + ways_right;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    if(grid[0][0] == -1) return 0;
    int zeroes = 1;

    int start_x = -1, start_y = -1;
    for(int i = 0;i < m; i++) {
        for(int j = 0;j < n; j++) {
            if(grid[i][j] == 0) zeroes++;
            else if(grid[i][j] == 1) {
                start_x = i;
                start_y = j;
            }
        }
    }

    int uniqueWays = countUniquePaths(start_x,start_y,m,n,grid,0,zeroes);
    return uniqueWays;
}

int main() {
    vector<vector<int>> grid = {{0,0,0,0,0,0,2,0,0,0},{0,0,0,0,0,0,0,0,1,0}};
    int uniqueWays = uniquePathsIII(grid);

    cout << "Total Number of Unique Ways -> " << uniqueWays << endl;
}