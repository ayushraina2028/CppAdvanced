#include <iostream>
#include <vector>
using namespace std;


int uniquePaths(int i, int j, int m, int n,vector<vector<int>>& dp) {
    if(i == m-1 or j == n-1) return 1;
    else if(dp[i][j] != -1) return dp[i][j];

    int ways = uniquePaths(i+1,j,m,n,dp) + uniquePaths(i,j+1,m,n,dp);
    return dp[i][j] = ways;
}

int main() {
    int m = 51;
    int n = 9;

    vector<vector<int>> dp;
    dp.clear();
    dp.resize(m,vector<int> (n,-1));

    int uniqueways = uniquePaths(0,0,m,n,dp);
    cout << uniqueways << endl;
    
}