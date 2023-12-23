#include <iostream>
#include <vector>

using namespace std;
int inversions = 0;

void merge(vector<int> nums1, vector<int> nums2, vector<int>& ans) {
    int i = 0;
    int j = 0;
    int k = 0;  

    int n = nums1.size(), m = nums2.size();
    // here at this point we need to count inversion before merging
    while(i < n and j < m) {
        if(nums1[i] < nums2[j]) {
            i++;
        }
        else if(nums1[i] > nums2[j]) {
            inversions += n-i;
            j++;
        }
    }

    i=0,j=0;

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


void mergeSort(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return;

    // calculate sizes
    int left_size = n/2;
    int right_size = n-left_size;

    // make new arrays for next call
    vector<int> a(left_size), b(right_size);
    for(int i=0,j=0; i<left_size,j<right_size; i++,j++) {
        a[i] = nums[i], b[j] = nums[left_size+i];
    }

    // recursive calls
    mergeSort(a);
    mergeSort(b);

    // for merging 2 arrays
    merge(a,b,nums);
}

int main() {
    vector<int> nums = {5,3,2,4,1};
    mergeSort(nums);

    for(auto el : nums) cout << el << " ";
    cout << endl;   

    cout << "Number of Inversions -> " << inversions << endl;
}