#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int f(int i, vector<int>& cost) {
    if(i >= cost.size()) return 0;
    else if(dp[i] != -1) return dp[i];

    int minCost = min(cost[i] + f(i+1,cost), cost[i] + f(i+2,cost));
    return dp[i] = minCost;
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if(n==1) return cost[0];
    else if(n==2) return min(cost[0], cost[1]);

    dp.clear();
    dp.resize(n,-1);

    int mincost = min(f(0,cost), f(1,cost));
    return mincost;
}

int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int minCost = minCostClimbingStairs(cost);
    cout << minCost << endl;
}