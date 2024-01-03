#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int> nums) {
    int n = nums.size();
    if(n==1) return 0;

    int lo = 0, hi = n-1, mid;
    if(nums[0] > nums[1]) return 0;
    else if(nums[n-1] > nums[n-2]) return n-1;

    while(lo <= hi) {
        mid = lo + (hi-lo)/2;

        if(nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]) return mid;

        else if(nums[mid] > nums[mid-1]) lo = mid+1;
        else if(nums[mid] < nums[mid-1]) hi = mid-1;

        else if(nums[mid] < nums[mid-1] and nums[mid] < nums[mid+1]) lo = mid+1;
    }

    return -1;
}

int main() {
    vector<int> nums = {1,2,1,3,5,6,4};
    int peakElement = findPeakElement(nums);

    cout << "One of the peak element is at index -> " << peakElement << endl;
}