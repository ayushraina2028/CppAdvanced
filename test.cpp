#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int steps = INT_MAX;

int f(int x, int y, int start, int end, int k) {
    if(x == start and y == end) return 0;
    else if(x < start or y < end) return INT_MAX;

    if(dp[start][end] != -1) return dp[start][end];

    int steps = 0;
    steps = 1 + min(f(x, y, start+k, end, k), f(x, y, start, end+k, k));
    if(steps == -2147483646 || steps == -2147483648 || steps == -2147483647) return dp[start][end] = INT_MAX;

    return dp[start][end] = steps;
}

int main() {
    

    int x = 2, y = 3;
    int small = min(x, y);

    for(int i = 1; i <= small; i++) {
        dp.clear();
        dp.resize(100, vector<int> (100, -1));
        steps = min(steps, f(x, y, 0, 0, i));
    }

    cout << steps << endl;
}