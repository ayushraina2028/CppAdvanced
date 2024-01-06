#include <iostream>
#include <vector>

using namespace std;

int findKthPositive(vector<int> arr, int k) {
    int n = arr.size();
    if(arr[n-1] == n) return n+k;

    else if(arr[0] > 1 and k <= arr[0]-1) {
        int misses = arr[0]-1;
        if (k <= misses) return k;
    }

    else if(arr[n-1] > n) {
        int misses = arr[n-1] - n;
        if(misses < k) return arr[n-1] - misses + k;
        
    }

    int lo = 0;
    int hi = n-1;
    int mid;

    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        int prev_lo = lo;
        int prev_hi = hi;

        int misses = arr[mid]-mid-1;

        if(misses < k) lo = mid;
        else if(misses >= k) hi = mid;

        if(lo == prev_lo and hi == prev_hi) break;
    }

    cout << lo << " " << hi << endl;

    int x = arr[lo]-lo-1;
    return arr[lo] + k - x;
}

int main() {
    vector<int> arr = {4,6,7,8,10};
    int k = 8;

    int missingnum = findKthPositive(arr,k);
    cout << missingnum << endl;
}