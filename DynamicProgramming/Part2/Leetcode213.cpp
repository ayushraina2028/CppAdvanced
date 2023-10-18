#include <iostream>
#include <vector>
using namespace std;

vector <int> dp;

int rob(vector <int> nums, int i) {
    if(i >= nums.size()) {
        return 0;
    }

    if(dp[i] != -1) return dp[i];

    int profit = 0;
    for(int j = 2;j < nums.size();j++) {
        profit = max(profit, nums[i] + rob(nums, i+j));
        dp[i] = profit;
    }

    return profit;
}

int rob2(vector <int> nums, int i) {
    if(i >= nums.size()-1) {
        return 0;
    }

    if(dp[i] != -1) return dp[i];

    int profit = 0;
    for(int j = 2;j < nums.size()-1;j++) {
        profit = max(profit, nums[i] + rob2(nums, i+j));
        dp[i] = profit;
    }

    return profit;
}

int main() {

    // Beats 100% users in c++;

    vector <int> nums = {2,7,9,1,3};
    int profit = 0;
    

    int n = nums.size();
    dp.resize(n,-1);


    for(int i = 1; i < nums.size(); i++) {
        profit = max(profit, rob(nums,i));
    }

    dp.clear();
    dp.resize(n,-1);

    for(int i = 0;i < nums.size();i++) {
        profit = max(profit, rob2(nums,i));
    }

    cout << profit << endl;    
}