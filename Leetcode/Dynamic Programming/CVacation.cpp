#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Problem Link -> https://atcoder.jp/contests/dp/tasks/dp_c
    int N;
    cin >> N;
    
    // bottom up solution is easy for this problem
    int a,b,c;
    cin >> a >> b >> c;

    vector<vector<int>> dp(N, vector<int> (3,-1));
    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = c;

    for(int i = 1;i < N;i++) {
        cin >> a >> b >> c;

        dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << endl;
    
    return 0;
}