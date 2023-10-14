#include <iostream>
#include <vector>
using namespace std;

// declaring global memory vector
vector <int> dp;

int fibo(int n) {
    // Base Case
    if(n == 0 || n == 1) return n;
    
    // dp check to identify if problem was solved earlier
    if(dp[n] != -1) return dp[n];

    // storing newly computed values
    return dp[n] = fibo(n-1) + fibo(n-2);

}

int main() {
    int n = 30;

    // clear for garbage, resize, initialize accordingly
    dp.clear();
    dp.resize(n+1, -1);

    cout << fibo(n) << endl;

    return 0;
}