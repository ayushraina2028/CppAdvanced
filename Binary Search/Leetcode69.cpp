#include <iostream>
using namespace std;

int mySqrt(int x) {
    
    if(x==1 || x == 0) return x;
    
    int lo = 1;
    int hi = x;
    int mid;

    while(lo <= hi) {   
        mid = lo + (hi-lo)/2;

        if(mid*mid == x) return mid;

        else if(mid*mid > x) {
            hi = mid-1;
        }

        else lo = mid+1;
    }

    return hi;
}

int main() {
    int n = 16;
    int squareroot = mySqrt(n);
    cout << squareroot << endl;
}