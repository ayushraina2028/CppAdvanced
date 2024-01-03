#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int> nums) {
    int lo = 0;
    int hi = nums.size()-1;

    int mid;
    if(hi == 0) return nums[hi];
    else if(nums[lo] != nums[lo+1]) return nums[lo];
    else if(nums[hi] != nums[hi-1]) return nums[hi];

    while(lo <= hi) {

        mid = lo + (hi-lo)/2;

        // break condition.
        if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]) return nums[mid];

        // eliminations
        if((mid % 2 == 0 and nums[mid] == nums[mid+1]) or (mid % 2 != 0 and nums[mid] == nums[mid-1])) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    int nonduplicate = singleNonDuplicate(nums);

    cout << "Single Non Duplicate Element is -> " << nonduplicate << endl;
}