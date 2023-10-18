#include <iostream>
#include <vector>
using namespace std;

vector <int> dp;

int helper(vector<int> nums, int i) {
    int n = nums.size();

    dp[n-1] = nums[n-1];
    dp[n-2] = max(nums[n-1], nums[n-2]);

    //if(n-3 < 0) return dp[0];
    
    for(int j = n-3;j>=0;j--) {
        dp[j] = max(dp[j+1],nums[j]+dp[j+2]);
        cout << dp[j] << " ";
    }

    return dp[0];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];

    dp.clear();
    dp.resize(n,-1);

    int profit = helper(nums,n-1);
    return profit;

}

int main() {
    // Bottom Up SOlution for House Robber Problem
    // Clearly Linear Solution
}