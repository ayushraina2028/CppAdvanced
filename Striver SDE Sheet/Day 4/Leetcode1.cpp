#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    vector<int> answer;
    unordered_map<int, int> map;
    for(int x : nums) {
        map[x] = -1;
    }

    unordered_set<int> set;
    for(int i = 0;i < nums.size(); i++) {

        if(map[nums[i]] == -1) map[nums[i]] = i;

        if(set.find(nums[i]) == set.end()) {
            set.insert(target - nums[i]);
        }
        else {
            answer.push_back(map[target-nums[i]]);
            answer.push_back(i);
        }
    }

    return answer;
}

int main() {
    vector<int> nums = {3,3};
    int target = 6;

    vector<int> ans = twoSum(nums,target);
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}