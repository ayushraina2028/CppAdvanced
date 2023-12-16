#include <iostream>
#include <vector>

using namespace std;

int maxSumSubarray(vector<int>& nums, int k) {
    int sum = 0;
    int n = nums.size();

    if(n < k) return 0;
    else {
        for(int i = 0; i < k; i++) sum += nums[i];
    }

    int maxsum = sum;
    int window = 0;
    for(int j = k; j < n; j++) {
        sum = sum - nums[j-k] + nums[j];
        if(maxsum < sum) {
            maxsum = sum;
            window = j-k+1;
        }
    }
    cout << "window starting from -> " << window << endl;
    return maxsum;
}

int main() {
    vector<int> nums = {7,1,2,5,8,4,9,3,6};
    int k = 4;

    int maxsum = maxSumSubarray(nums,k);
    cout << maxsum << endl;
}