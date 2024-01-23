#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int j, int& n, vector<vector<int>>& matrix) {
    if(i == n) return 0;
    else if(dp[i][j] != -1) return dp[i][j];

    int minSum = matrix[i][j];
    int x = INT_MAX;

    for(int k = 0;k < n; k++) {
        if(k == j) continue;
        x = min(x,f(i+1,k,n,matrix));
    }

    minSum += x;
    return dp[i][j] = minSum;
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int minSum = INT_MAX;
    int n = matrix.size();

    dp.clear();
    dp.resize(n, vector<int> (n,-1));

    for(int j = 0;j < matrix.size(); j++) {
        minSum = min(minSum, f(0,j,n,matrix));
    }

    return minSum;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int fallingSum = minFallingPathSum(matrix);

    cout << "Minimum Falling Sum -> " << fallingSum << endl;
}