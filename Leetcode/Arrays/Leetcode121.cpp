#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> nums) {
    int maxProfit = 0;
    int curr_element = nums[0];
    int n = nums.size();

    for(int i = 1; i < n; i++) {

        int curr_profit = nums[i]-curr_element;
        if(curr_profit < 0) {
            curr_element = nums[i];
        }
        else {
            maxProfit = max(maxProfit, curr_profit);
        }
    }

    return maxProfit;
    
}

int main() {
 
    vector<int> nums = {7,1,5,3,6,4};
    int profit = maxProfit(nums);
    cout << profit << endl;

}