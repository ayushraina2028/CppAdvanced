#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

vector<vector <long long int>> dp;

long long int f(int n, int k, int target) {
    if(n == 0 and target == 0) return 1;
    else if(n == 0) return 0;

    if(dp[n][target] != -1) return dp[n][target];

    long long int count = 0;
    for(int i = 1;i <= k;i++) {
        if(i > target) continue;
        count = ((count % mod) + (f(n-1,k,target-i) % mod)) % mod;
    }

    return dp[n][target] = count;
}

int main() {

    // In this case we require 2 dimensional DP vector


    int n = 20;
    int k = 19;
    int target = 233;

    dp.clear();
    dp.resize(35,vector<long long int> (1007,-1));
    
    long long int ways = f(n,k,target);
    cout << ways << endl;
}