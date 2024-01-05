#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> dx = {-2,-1,-2,-1,+2,+1,+2,+1};
vector<int> dy = {+1,+2,-1,-2,+1,+2,-1,-2};

void display(vector<vector<int>>& grid) {
    for(auto row : grid) {
        for(auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

bool canWeMove(vector<vector<int>>& grid, int x, int y, int n) {
    return x >= 0 and y >= 0 and x < n and y < n and grid[x][y] == -1;
}

void f(int n, int i, int j, int count,vector<vector<int>>& grid) {
    if(count == n*n) {
        grid[i][j] = count;
        display(grid);
        cout << "*****************" << endl;
        grid[i][j] = -1;
        return;
    }

    for(int k = 0;k < 8; k++) {

        if(canWeMove(grid,i+dx[k],j+dy[k],n)) {
            grid[i][j] = count;
            f(n,i+dx[k], j+dy[k], count+1, grid);
            grid[i][j] = -1;
        }

    }
}

void knightsTour(int i, int j, int n) {

    vector<vector<int>> grid(n, vector<int>(n,-1));
    f(n,i,j,1,grid);

}

int main() {
    knightsTour(0,0,5);
}