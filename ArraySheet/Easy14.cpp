#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int getLongestSubArray(vector<int> nums, int k) {
    unordered_map<int, int> map;
    int sum = 0;
    int maxLen = 0;

    for(int i = 0;i < nums.size(); i++) {

        sum += nums[i];

        if(sum == k) {
            maxLen = i+1;
        }

        else if(map.find(sum-k) != map.end()) {
            maxLen = max(maxLen,i-map[sum-k]);
        }

        else if(map.find(sum) == map.end()) {
            map[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {2,-3,4,0,-4,-1,1};
    int k = 0;

    int maxLen = getLongestSubArray(nums, k);
    cout << maxLen << endl;
}