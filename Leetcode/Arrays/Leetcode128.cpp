#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std; 

int longestConsecutiveSequence(vector<int> nums) {
    int count = 0;
    int n = nums.size();

    unordered_set<int> set;
    for(auto ele : nums) {
        set.insert(ele);
    }

    int maxcount = 0;
    for(int x : set) {
        // if x-1 is not in set
        if(set.find(x-1) == set.end()) {
            count = 1;
            bool flag = true;
            int i = 1;
            while(flag) {
                if(set.find(x+i) != set.end()) count++;
                else {
                    flag = false;
                    maxcount = max(maxcount,count);
                    count = 0;
                }
                i++;
            }
        }
    }

    return maxcount;
}

int main() {
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    int longestLength = longestConsecutiveSequence(nums);
    cout << longestLength << endl;
}