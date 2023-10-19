#include<iostream>
#include<vector>
#include <climits>
using namespace std;

vector<int> dp;

int f(int cost, vector<int>& coins) {

    // Base Cases
    if(cost == 0) return 0;
    else if(cost < 0) return -1;

    // returning memoized answer;
    if(dp[cost] != -2) return dp[cost];

    // Main work
    int result = INT_MAX;
    for(int i = 0;i < coins.size(); i++) {
        int value = f(cost-coins[i], coins);

        if(value != -1) {
            result = min(result, value+1);
        }
    }

    // if resutl was not updated
    if(result == INT_MAX) result = -1;
    return dp[cost] = result;

}

int main() {
    int n,cost;
    cin >> n >> cost;

    dp.resize(cost+1,-2);

    vector<int> coins(n);
    for(int i = 0;i < n;i++) {
        cin >> coins[i];
    }

    int coins_req = f(cost,coins);
    cout << coins_req << endl;

    return 0;
}