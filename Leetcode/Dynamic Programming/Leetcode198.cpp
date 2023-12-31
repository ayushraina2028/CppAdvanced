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

int main() {

    // Beats 100% users in c++;

    vector <int> nums = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    int profit = 0;
    

    int n = nums.size();
    dp.resize(n,-1);


    for(int i = 0; i < nums.size(); i++) {
        profit = max(profit, rob(nums,i));
    }
    cout << profit << endl;    
}