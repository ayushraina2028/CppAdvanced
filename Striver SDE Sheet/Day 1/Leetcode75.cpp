#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortColors(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size()-1;
    int mid = 0;

    if(hi==1) {
        if(nums[0] > nums[1]) swap(nums[0], nums[1]);
        return;
    }

    cout << lo << " " << mid << " " << hi << endl;
    while(lo <= hi and mid <= hi) {

        if(nums[mid] == 0) {
            swap(nums[mid], nums[lo]);
            lo++;

            if(nums[mid] == 0) mid++;
        }
        else if(nums[mid] == 2) {
            swap(nums[mid], nums[hi]);
            hi--;
        }
        else if(nums[mid] == 1) {
            mid++;
        }
    }
    return;
}

int main(){

    vector<int> nums = {0,1,0};
    sortColors(nums);
    for(auto ele : nums) {
        cout << ele << " ";
    }
    cout << endl;

}