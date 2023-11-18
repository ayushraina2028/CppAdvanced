#include <iostream>
#include <vector>

using namespace std;

void func1(vector<int> nums) {
    int n  = nums.size();
    bool flag = true;
    int maxCount = 1;
    for(int i = 0;i < n; i++) {
        int temp = nums[i];
        int count = 1;
        for(int j = i+1; j < n; j++) {
            
            if(nums[j] > temp and flag == false) {
                flag = true;
                count++;
                temp = nums[j];
            }

            else if(nums[j] > temp and flag == true) {
                continue;
            }

            else if(nums[j] < temp and flag == true) {
                flag = false;
                temp = nums[j];
                count++;
            }

            else if(nums[j] < temp and flag == false) {
                continue;
            }
        }
        
        maxCount = max(count, maxCount);
    }

    cout << "Max iter: " << maxCount << endl;
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 49, 50, 31, 60};
    func1(nums);
}