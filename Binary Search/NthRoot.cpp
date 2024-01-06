#include <iostream>
using namespace std;

int mySqrt(int num, int n) {
    if(num ==1 || num == 0) return num;
    
    int lo = 1;
    int hi = num;
    int mid;

    while(lo <= hi) {   
        mid = lo + (hi-lo)/2;

        long long int new_mid = mid;
        for(int i = 0;i < n-1; i++) {
            new_mid *= mid;
            if(new_mid > num) break;
        }
        if(new_mid == num) return mid;

        else if(new_mid > num) {
            hi = mid-1;
        }

        else lo = mid+1;
    }

    return -1;
}

int main() {
    int num = 1953125;
    int n = 9;
    int squareroot = mySqrt(num,n);
    cout << squareroot << endl;
}