#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> majorityElementII(vector<int> nums) {
    
    vector<int> answer;
    sort(nums.begin(), nums.end());

    int window_size = nums.size()/3;
    window_size++;

    int sum = 0;
    for(int i = 0;i < window_size; i++) {
        sum += nums[i];
    }

    int last_push = -1;
    if(sum == window_size*nums[0]) {
        answer.push_back(nums[0]);
        last_push = nums[0];
    }

    int i = window_size;
    
    while(i < nums.size()) {
        sum = sum + nums[i] - nums[i-window_size];
        if(sum == window_size*nums[i]) {
            if(nums[i] != last_push) {
                answer.push_back(nums[i]);
                last_push = nums[i];
            }
        }
        i++;
    }

    return answer;
}

int main() {
    vector<int> nums = {2,2};
    vector<int> answer = majorityElementII(nums);

    for(auto ele : answer) cout << ele << " ";
    cout << endl;
}