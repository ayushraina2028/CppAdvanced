#include <iostream>
#include <vector>

using namespace std;

bool canWeDivide(int divisor, vector<int> nums, int threshold) {
    int remainder = 0;
    for(int i = 0;i < nums.size(); i++) {

        if(nums[i] % divisor == 0) {
            remainder += nums[i]/divisor;
        }
        else if(nums[i] % divisor != 0) {
            remainder++;
            remainder += nums[i]/divisor;
        }

    }

    if(remainder <= threshold) return true;
    return false;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int maxi = nums[0];
    for(int i = 1;i < nums.size(); i++) {
        if(maxi < nums[i]) maxi = nums[i];
    }

    int lo = 1;
    int hi = maxi;
    int mid;
    int smallestdivisor = maxi;

    while(lo <= hi) {
        mid = lo + (hi-lo)/2;

        if(canWeDivide(mid,nums,threshold)) {
            smallestdivisor = mid;
            hi = mid-1;
        }

        else lo = mid+1;

    }

    return smallestdivisor;
}

int main() {
    vector<int> nums = {44,22,33,11,1};
    int threshold = 5;

    int smallestdiv = smallestDivisor(nums,threshold);
    cout << smallestdiv << endl;
}