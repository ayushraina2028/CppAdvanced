#include <iostream>
#include <vector>

using namespace std;

void maxValue(vector<int>& nums, int i, int max) {
    if(i == nums.size()) {
        cout << max << endl;
        return;
    }

    if(max < nums[i]) {
        return maxValue(nums,i+1,nums[i]);
    }
    else {
        return maxValue(nums,i+1,max);
    }
}

void display(vector<int>& nums,int i) {
    if(i == nums.size()) return;

    cout << nums[i] <<  " ";
    display(nums,i+1);
}

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7};
    display(nums,0);
    cout << endl;
    maxValue(nums,0,-1);
}