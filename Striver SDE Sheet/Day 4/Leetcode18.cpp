#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> answer;
    sort(nums.begin(),nums.end());
    int n = nums.size();

    for(int i = 0;i < n; i++) {
        if(i > 0 and nums[i] == nums[i-1]) continue;

        for(int j = i+1;j < n; j++) {
            if(j > i+1 and nums[j] == nums[j-1]) continue;

            int k = j+1;
            int l = n-1;

            while(k < l) {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if(target == sum) {
                    answer.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++; l--;

                    while(k < l and nums[k] == nums[k-1]) k++;
                    while(k < l and nums[l] == nums[l+1]) l--;
                }
                else if(sum < target) k++;
                else l--;
            }
        }
    }
    return answer;
}

int main() {
    vector<int> nums = {4,-9,-2,-2,-7,9,9,5,10,-10,4,5,2,-4,-2,4,-9,5};
    int target = -13;

    vector<vector<int>> ans = fourSum(nums,target);
    for(auto row : ans) {
        for(auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}