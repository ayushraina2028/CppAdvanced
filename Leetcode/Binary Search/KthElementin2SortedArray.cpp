#include <bits/stdc++.h>
using namespace std;

// This is good concept.
int findKthElement(vector<int> nums1, vector<int> nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    if(n1 > n2) return findKthElement(nums2,nums1,k);
    else if(k == n1+n2) return max(nums1[n1-1], nums2[n2-1]);

    int lo = max(0,k-n2);
    int hi = min(k,n1);
    int mid1, mid2;

    while(lo <= hi) {
        mid1 = lo + (hi-lo)/2;
        mid2 = k-mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 > 0) l1 = nums1[mid1-1];
        if(mid2 > 0) l2 = nums2[mid2-1];

        if(l1 <= r2 and l2 <= r1) {
            return max(l1,l2);
        }   

        else if(l1 > r2) hi = mid1-1;
        else lo = mid1+1;

    }

    return -1;
}

int main() {
    vector<int> nums1 = {1,3,4,7,10,12};
    vector<int> nums2 = {2,3,6,15};

    int k = 8;

    int kthelement = findKthElement(nums1, nums2, k);
    cout << kthelement << endl;
}