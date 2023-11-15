#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<long long>> dp;

long long f(vector<int>& nums, int idx, int subseq, int k) {
    if(k < 0) return  INT_MAX;
    else if(idx == nums.size()) return 0;

    if(dp[idx][subseq] != -1) return dp[idx][subseq];

    long long  minDiff = min(f(nums, idx+1, subseq+1, k-1), subseq+nums[idx]+f(nums, idx+1, subseq, k));
    return dp[idx][subseq] = minDiff;
}

int main() {

    dp.clear();

    vector<int> nums = {8,2,5,15,11,2,8};
    int k = 5;      
    int n = nums.size();
    dp.resize(n+2, vector<long long int> (n+2, -1));

    long long minDifficulty = f(nums, 0, 0, k);
    cout << minDifficulty << endl;

    
}