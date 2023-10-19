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
    for(int coin : coins) {
        int value = f(cost-coin, coins);

        // if we receive -1 then result will not be updated and will be handled below outside this loop
        if(value != -1) {
            result = min(result, value+1);
        }
    }

    // if result was not updated
    if(result == INT_MAX) result = -1;
    return dp[cost] = result;

}

int main() {

    //problem link -> https://cses.fi/problemset/task/1634

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