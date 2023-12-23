#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, vector<int> nums2) {
    int m = nums2.size();
    int n = nums1.size()-m;
    
    int i = n-1;
    int j = m-1;
    int k = nums1.size()-1;
    
    cout << i << j << k << endl;

    while(i >= 0 and j >= 0) {
        if(nums1[i] < nums2[j]) {
            nums1[k] = nums2[j];
            k--, j--;
        }

        else if(nums1[i] >= nums2[j]) {
            nums1[k] = nums1[i];
            i--, k--;
        }
    }

    if(i < 0 and j >= 0) {
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--, k--;
        }
    }

    else if(i >= 0 and j < 0) {
        while(i >= 0) {
            nums1[k] = nums1[i];
            i--, k--;
        }
    }
    return;
}

int main() {
    vector<int> nums1 = {4,0,0,0,0,0};
    vector<int> nums2 = {1,2,3,4,5};

    merge(nums1, nums2);

    for(auto integer : nums1) cout << integer << " ";
    cout << endl;
}