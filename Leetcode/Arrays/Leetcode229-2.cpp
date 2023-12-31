#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> majorityElementII(vector<int> nums) {
    // easiest O(n) solution 
    vector<int> answer;
    unordered_map<int, int> map;

    for(auto element : nums) {
        map[element]++;
    }

    int window_size = nums.size()/3;
    window_size++;

    for(auto element : map) {
        if(element.second >= window_size) answer.push_back(element.first);
    }

    return answer;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    vector<int> answer = majorityElementII(nums);

    for(auto ele : answer) cout << ele << " ";
    cout << endl;
}