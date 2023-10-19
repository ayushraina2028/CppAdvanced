#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

vector<int> dice = {1,2,3,4,5,6};
vector<long long int> dp;

long long int f(int n) {  

    if(n == 0) { 
        return 1;
    }

    if(dp[n] != -1) return dp[n];

    long long int count = 0;
    for(int x : dice) {
        if(x > n) break;
        count = ((count % mod) + (f(n-x) % mod)) % mod;
    }
    
    return dp[n] = count;
}

int main() {

    int n;
    cin >> n;

    dp.clear();
    dp.resize(n+7,-1);

    cout << f(n) << endl;
    // this code is correct but I am not able to apply dp here.
}