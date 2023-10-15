#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int f(int n) {


    if(n == 1 || n == 2) {
        return n;
    }

    // check memory for answer
    if(dp[n] != -1) return dp[n];

    // save the computed answers for future use
    // below one is our recurrence relation
    int ways = f(n-1) + (n-1)*f(n-2);
    dp[n] = ways;

    return ways;
}

int main() {
    int n = 5;
    dp.clear();
    dp.resize(n+1, -1);
    cout << f(n) << endl;
    return 0;
}