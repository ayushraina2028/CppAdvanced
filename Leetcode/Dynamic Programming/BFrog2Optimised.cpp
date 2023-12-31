#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> heights;
int n, k;
vector<int> dp;

int minCostForEnd(int i) {

    // base case
    if(i == n-1) {
        return 0;
    }

    // check in dp
    if(dp[i] != -1) return dp[i];

    // main search
    int minCost = INT_MAX;
    for(int j = 1;j <= k;j++) {
        if(i + j < n) {
            minCost = min(minCost, abs(heights[i+j]-heights[i]) + minCostForEnd(i+j));
            dp[i] = minCost;
        }
        else {
            break;
        }
    }
    return minCost;
}

int main() {
    cin >> n >> k;

    heights.clear();
    heights.resize(n);
    for(int i = 0;i < n; i++) {
        cin >> heights[i];
    }

    dp.clear();
    dp.resize(n,-1);
    dp[n-1] = 0;

    cout << minCostForEnd(0) << endl;
}