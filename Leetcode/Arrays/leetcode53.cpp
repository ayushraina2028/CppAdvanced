#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> nums) {
    int maxsum = nums[0];
    int sum = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        
        if(sum < 0) {
            sum = 0;
        }
        sum += nums[i];
        maxsum = max(maxsum, sum);

    }

    return maxsum;
}

int main(){
    vector<int> nums = {-2,-1};
    int maxsum = maxSubArray(nums);
    cout << maxsum << endl;

}