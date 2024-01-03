#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> nums) {
    int lo = 0;
    int hi = nums.size()-1;

    int mid;

    while(lo <= hi) {
        mid = lo + (hi-lo)/2;

        // breaking conditions
        if(mid > lo and nums[mid] < nums[mid-1]) return nums[mid];
        else if(mid < hi and nums[mid] > nums[mid+1]) return nums[mid+1];

        // eliminating portions
        if(nums[mid] > nums[hi]) lo = mid+1;
        else hi = mid-1;
    }

    return nums[0];
}

int main() {
    vector<int> nums = {11,13,15,17};

    int minimum = findMin(nums);

    cout << "minimum element found is -> " << minimum << endl;
}