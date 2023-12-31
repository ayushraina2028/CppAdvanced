#include <iostream>
#include <vector>

using namespace std;

int f(vector<int>& nums, int i, int j) {

    if(i == nums.size()) return 1;

    int maxlen = 0;
    
    if(nums[i+1] < nums[i] and j == 0) {
        maxlen = max(1+f(nums,i+1,1), f(nums,i+1,1));
    }

    else if(nums[i+1] > nums[i] and j == 1) {
        maxlen = max(1+f(nums,i+1,0), f(nums, i+1, 0));
    }

    else if(nums[i+1] < nums[i] and j == 1) {
        maxlen = max(maxlen, f(nums,i+1,0));
    }

    else if(nums[i+1] > nums[i] and j == 0) {
        maxlen = max(maxlen,f(nums, i+1, 1));
    }
    

    return maxlen;
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 49, 50, 31, 60};

    int lenLOS = f(nums,0,0);
    cout << lenLOS << endl;
}