#include <bits/stdc++.h>
using namespace std;
 
int solve(vector<int> &a, int n, int x, vector<int> &dp)
{
 
    if (x == 0)
        return 0;
    if (x < 0)
        return -1;
 
    if (dp[x] != -2)
        return dp[x];
 
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int val = solve(a, n, x - a[i], dp);
 
        if (val != -1)
            ans = min(ans, val + 1);
    }
 
    if (ans == INT_MAX)
        ans = -1;
    return dp[x] = ans;
}
 
int main()
{
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    vector<int> dp(x + 1, -2);
 
    int ans = solve(a, n, x, dp);
    cout << ans;
 
    return 0;
}