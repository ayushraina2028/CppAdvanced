#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

bool f(int n,int L, int K) {
    if( n==1 || n==L || n==K || n<0 ) return true;

    if(dp[n] != -1) return true;

    if(f(n-1,L,K) and f(n-L,L,K) and f(n-K,L,K)) {
        return false;
    }
    else {
        dp[n]=2;
        return true;
    }
}

int main() {
    // Problem Link -> https://www.spoj.com/problems/MCOINS/
    int K, L, m;
    cin >> K >> L >> m;

    vector<int> coins(m,-1);
    for(int i = 0;i < m;i++) {
        cin >> coins[i];
    }

    dp.clear();
    dp.resize(1000006,-1);

    for(int n : coins) {
        if(f(n,L,K)) {
            cout << "A";
        }
        else {
            cout << "B";
        }
    }

}