#include <iostream>
#include <vector>

using namespace std;

int searchII(vector<int> nums, int target) {
    int low = 0;
    int hi = nums.size()-1;
    int mid;

    while(low <= hi) {
        mid = low + (hi-low)/2;

        // case I
        if(nums[mid]==target) {
            return mid;
        }

        // additional case
        else if(nums[mid]==nums[low] and nums[mid]==nums[hi]) {
            low++;
            hi--;
            continue;
        }

        // case II: left portion is sorted
        if(nums[low] <= nums[mid]) {
            if(target >= nums[low] and target <= nums[mid]) {
                hi = mid-1;
            }
            else low = mid+1;
        }

        // Case III: right portion is sorted.
        else if(nums[mid] <= nums[hi]) {
            if(target >= nums[mid] and target <= nums[hi]) {
                low = mid+1;
            }
            else hi = mid-1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1,0,1,1,1};
    int target = 0;

    int idx = searchII(nums,target);

    if(idx == -1) cout << "Element is not found." << endl;
    else cout << "Element is found at index -> " << idx << endl;
}