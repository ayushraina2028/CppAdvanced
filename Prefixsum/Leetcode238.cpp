#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> nums) {
    // use concept of next product and previous product array
    int n = nums.size();
    vector<int> prefixProduct(n,1);
    vector<int> suffixProduct(n,1);
    vector<int> answer(n,1);


    // fill prefix array
    for(int i = 1; i < nums.size(); i++) {
        prefixProduct[i] = prefixProduct[i-1]*nums[i-1];
    }

    // fill suffix array
    for(int i = n-2; i >= 0; i--) {
        suffixProduct[i] = suffixProduct[i+1]*nums[i+1];
    }
    
    // filling answer array
    for(int i = 0; i < n; i++) {
        answer[i] = prefixProduct[i]*suffixProduct[i];
    }

    return answer;
}

int main() {
    vector<int> nums = {1,2,3,4};

    vector<int> ans = productExceptSelf(nums);
    for(auto ele : ans) {
        cout << ele << " ";
    }
    cout << endl;
}