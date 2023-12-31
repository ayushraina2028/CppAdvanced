#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nextpermutation(vector<int> nums) {
    int n = nums.size();

    int pivot_idx = n;
    for(int j = n-2;j >= 0; j--) {
        if(nums[j] < nums[j+1]) {
            pivot_idx = j;
            break;
        }
    }

    cout << pivot_idx << endl;
    if(pivot_idx == n) {
        reverse(nums.begin(), nums.end());
    }
    else {
        int swap_idx = -1;
        for(int i = pivot_idx+1; i < n; i++) {
            if(nums[i] <= nums[pivot_idx]) {
                swap_idx = i-1;
                break;
            }
        }

        if(swap_idx == -1) swap_idx = n-1;

        swap(nums[pivot_idx], nums[swap_idx]);
        reverse(nums.begin() + pivot_idx + 1, nums.end());
    }

    return nums;
}

int main(){
    vector<int> nums = {5,4,7,5,3,2};
    vector<int> next = nextpermutation(nums);

    for(auto ele : next) {
        cout << ele << " ";
    }
    cout << endl;
}