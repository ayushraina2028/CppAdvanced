#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        // maintain priority_queue
        priority_queue<int, vector<int>, greater<int> > minHeap(nums.begin(), nums.end());
        int sum = 0;

        for(auto element:nums) {
            sum += element;
        }
        cout << sum << endl;

        while(k--) {
            int ele = minHeap.top();
            if(ele == 0) {
                break;
            }
            minHeap.pop();
            cout << ele << endl;
            // push negated one
            minHeap.push(-1*ele);

            // update sum
            sum += (-2*ele);
        }

        return sum;
    }
};

int main() {
    return 0;
}