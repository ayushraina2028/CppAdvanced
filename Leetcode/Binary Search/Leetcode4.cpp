#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n1 > n2) return findMedianSortedArrays(nums2,nums1);

    int lo = 0;
    int hi = n1;
    int mid1, mid2;

    int required = (n1 + n2 + 1)/2;
    while(lo <= hi) {
        
        mid1 = lo + (hi-lo)/2;
        mid2 = required - mid1;

        int left1 = INT_MIN, left2 = INT_MIN, right1 = INT_MAX, right2 = INT_MAX;

        // checks and updates
        if(mid1 < n1) right1 = nums1[mid1];
        if(mid2 < n2) right2 = nums2[mid2];
        if(mid1 > 0) left1 = nums1[mid1-1];
        if(mid2 > 0) left2 = nums2[mid2-1];

        if(left1 <= right2 and left2 <= right1) {
            if((n1+n2) % 2 == 0) {
                double median = (double)(max(left1, left2) + min(right1, right2))/2.0;
                return median;
            }
            else return (double)max(left1,left2);
        }

        else if(left1 > right2) hi = mid1-1;
        else lo = mid1+1;
        
    }

    return -1;
}

int main() {
    vector<int> nums1 = {1,3,4,7,10,12};
    vector<int> nums2 = {2,3,6,15};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << median << endl;
}