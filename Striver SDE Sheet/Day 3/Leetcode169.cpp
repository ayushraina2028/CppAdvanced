#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int element = nums[0];
    int count = 1;

    for(int i = 1;i < nums.size(); i++) {
        if(count == 0) {
            element = nums[i];
            count = 1;
        }

        else if(element == nums[i]) {
            count++;
        }

        else count--;
    }

    return element;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
}