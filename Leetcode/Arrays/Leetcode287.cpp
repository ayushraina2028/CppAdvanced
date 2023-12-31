#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a nice one.
int findDuplicate(vector<int> nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        int idx = nums[i];
        if(idx < 0) idx *= -1;

        if(nums[idx] < 0) return idx;
        else nums[idx] *= -1;
    }

    return -1;
}

int findMissing(vector <int> nums) {
    int n = nums.size();

    for(int i = 0;i < n; i++) {
        int idx = nums[i];
        if(idx < 0) idx *= -1;
        idx--;

        if(nums[idx] > 0) nums[idx] *= -1;
        else {
            break;
        }
    }

    int idx = -1;
    for(int i = 0;i < n; i++) {
        if(nums[i] > 0) {
            idx = i;
            break;
        }
    }

    return idx+1;
}

int main() {
    vector<int> nums1 = {1,3,4,2,2};
    int duplicate = findDuplicate(nums1);
    cout << duplicate << endl;

    int missing = findMissing(nums1);
    cout << missing << endl;
}