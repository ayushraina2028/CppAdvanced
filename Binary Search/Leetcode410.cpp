#include <bits/stdc++.h>
using namespace std;

bool canWeDistribute(int number, vector<int>& nums, int k) {
    int students = 1;
    int curr_number = number;

    int i = 0;
    while(i < nums.size()) {

        if(nums[i] <= curr_number) {
            curr_number -= nums[i];
            i++;
        }
        else if(nums[i] > curr_number) {
            students++;
            curr_number = number;
        }

    }

    // when capacity is lo, n students are there and on hi 1 student, so we move towards left -> increasing students
    // remember above line, this problem is same as book allocation.
    if(students <= k) return true;
    return false;
}

int splitArray(vector<int> nums, int k) {
    if(k > nums.size()) return -1;
    int sum = nums[0];
    int maxele = nums[0];

    for(int i = 1;i < nums.size(); i++) {
        if(maxele < nums[i]) maxele = nums[i];
        sum += nums[i];
    }

    if(k == nums.size()) return maxele;

    int lo = maxele;
    int hi = sum;
    int mid = 0;

    int minofmaxsum = sum;
    while(lo <= hi) {

        mid = lo + (hi-lo)/2;
        if(canWeDistribute(mid,nums,k)) {
            minofmaxsum = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    return minofmaxsum;
}

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int k = 5;

    int minmaxsum = splitArray(nums,k);
    cout << minmaxsum << endl;
}