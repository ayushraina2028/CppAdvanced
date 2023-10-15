#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> heights;
int n, k;
vector<int> dp;

int minCostForEnd() {


    // move back from n-2 to start.
    for(int i = n-2; i >= 0; i--) {
        for(int j = 1;j <= k; j++) {
            if(i+j < n) {
                dp[i] = min(dp[i], abs(heights[i+j]-heights[i]) + dp[i+j]);
            }
            else {
                break;
            }
        }
    }

    return dp[0];
}

int main() {
    cin >> n >> k;

    heights.clear();
    heights.resize(n);
    for(int i = 0;i < n; i++) {
        cin >> heights[i];
    }

    dp.clear();
    dp.resize(n,INT_MAX);
    dp[n-1] = 0;

    cout << minCostForEnd() << endl;
}