#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector <int> dp;

vector<int> get_digits(int n) {
    vector<int> digits;
    while(n > 0) {
        // push only non zero digits.
        if(n % 10 != 0) digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

int f(int n) {
    if(n==0) return 0;
    if(n <= 9) return 1;

    vector<int> digits = get_digits(n);
    
    if(dp[n] != -1) return dp[n];

    int steps = INT_MAX;

    for(auto element : digits) {
        steps = min(steps, f(n-element));
    }
    
    return dp[n] = 1 + steps;
}

int main() {
    // Link -> https://cses.fi/problemset/task/1637
    int n;
    cin >> n;

    dp.clear();
    dp.resize(1000007,-1);

    cout << f(n) << endl;
    
}