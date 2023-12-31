#include <iostream>
#include <vector>

using namespace std;

void findSubarrays(vector<int> nums, vector<vector<int>>& answer,vector<int> helper, int i) {
    if(i == nums.size()) {
        answer.push_back(helper);
        return;
    }

    findSubarrays(nums, answer, helper, i+1);
    if(helper.size() == 0 or nums[i-1] == helper[helper.size()-1]) {
        helper.push_back(nums[i]);
        findSubarrays(nums, answer, helper, i+1);
    }
    return;
}

int main() {
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> subarrays;

    vector<int> v;
    findSubarrays(nums, subarrays, v, 0);


    for(auto row : subarrays) {
        for(auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}