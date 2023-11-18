#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int main() {
    vector<vector<int>> matrix = {{1,0,1,0,0}, {1,0,1,1,1}, {1,1,1,1,1}, {1,0,0,0,0}};
    int n = matrix.size();
    int m = matrix[0].size();
    cout << n << " " << m << endl;

    dp.clear();
    dp.resize(n, vector<int> (m,0));

    for(int i = 0;i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0) {
                dp[i][j] = matrix[i][j];
            }
            else {
                dp[i][j] = dp[i-1][j] + matrix[i][j];
            }
        }
    }

    // check our dp vector
    for(auto row : dp) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    // now iterate

}