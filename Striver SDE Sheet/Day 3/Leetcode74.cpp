#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size();

    int mid;
    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        if(nums[mid]==target) return true;
        else if(nums[mid] < target) lo = mid+1;
        else hi = mid-1;
    }

    return false;
}

bool searchMatrix(vector<vector<int>>& nums, int target) {
    int cols = nums[0].size();
    for(auto row : nums) {
        if(target >= row[0] and target <= row[cols-1]) {
            return binarySearch(row,target);
        }
    }

    return false;
}

int main() {
    vector<vector<int>> nums = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int target = 16;

    cout << searchMatrix(nums,target) << endl;
}