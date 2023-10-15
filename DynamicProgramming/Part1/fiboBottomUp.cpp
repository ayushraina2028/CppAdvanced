#include <iostream>
#include <vector>
using namespace std;

// Bottom Up solution for fibonacchi.
int fibo(int n) {

    // Initialize dp array
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    // proceed further
    for(int i = 2;i <= n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fibo_optimised(int n) {
    // here we will optimise space complexity 

    int dp_0 = 0;
    int dp_1 = 1;
    int dp_n;
    
    for(int i = 2;i <= n;i++) {
        dp_n = dp_0 + dp_1;
        dp_0 = dp_1;
        dp_1 = dp_n; 
    }

    return dp_n;
}

int main() {
    cout << fibo(20) << endl;
    cout << fibo_optimised(20) << endl;
}