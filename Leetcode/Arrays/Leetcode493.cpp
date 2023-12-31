#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> nums1, vector<int> nums2, vector<int>& ans,int& count) {
    int i = 0;
    int j = 0;
    int k = 0;  

    int n = nums1.size(), m = nums2.size();

    // at this point we need to check our required condition 
    // at this position we can further use binary search;
    while(i < n and j < m) {
        if(nums1[i] > 0 and nums2[j] < 0) {
            count += n-i;
            j++;
        }
        else if(nums1[i] < 0 and nums2[j] > 0) {
            i++;
        }
        else if(nums1[i] - nums2[j] > nums2[j]) {
            count += n-i;
            j++;
        }
        else i++;
    }

    // set i and j back to 0
    i=0;j=0;

    while(i < n and j < m) {
        if(nums1[i] <= nums2[j]) {
            ans[k] = nums1[i];
            i++, k++;
        }
        else {
            ans[k] = nums2[j];
            k++, j++;
        }
    }

    // remainig other cases
    if(i == n and j != m) {
        while(j != m) {
            ans[k] = nums2[j];
            j++, k++;
        }
    }

    else if(i != n and j == m) {
        while(i != n) {
            ans[k] = nums1[i];
            i++, k++;
        }
    }

    return;
}


void mergeSort(vector<int>& nums, int& k) {
    int n = nums.size();
    if(n==1) return;

    // calculate sizes
    int left_size = n/2;
    int right_size = n-left_size;

    // make new arrays for next call
    
    vector<int> a(left_size), b(right_size);
    for(int i = 0;i < left_size; i++) {
        a[i] = nums[i];
    }
    for(int i = 0;i < right_size; i++) {
        b[i] = nums[i+left_size];
    }

    // recursive calls
    mergeSort(a,k);
    mergeSort(b,k);

    // for merging 2 arrays
    merge(a,b,nums,k);
}

int reversePairsII(vector<int>& nums) {
    int count = 0;
    mergeSort(nums,count);

    return count;
}

// O(n^2) Leetcode not accepting this
int reversePairsI(vector<int>& nums) {
    int count = 0;
    for(int i = 0;i < nums.size(); i++) {
        for(int j = i+1;j < nums.size(); j++) {
            if(nums[i] > 0 and nums[j] < 0) count++;
            else if(nums[i] < 0 and nums[j] > 0) continue;
            else {
                if(nums[i] - nums[j] > nums[j]) count++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums = {2,4,3,5,1};
    int pairs = reversePairsI(nums);
    int pairs2 = reversePairsII(nums);
    cout << pairs << " " << pairs2 << endl;
}