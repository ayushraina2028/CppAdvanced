#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long int dp[2005][2005][8];

long long int f(string& s1,string &s2, int i, int j, int k) {
    
    if(i == s1.length() || j == s2.length()) {
        return 0;
    }

    if(dp[i][j][k] != 0) return dp[i][j][k];

    // recurrence relation;
    if(s1[i] == s2[j]) {
        return dp[i][j][k] = 1 + f(s1, s2, i+1, j+1, k);
    }
    else {
        if(k <= 0) {
            return dp[i][j][k] = max(f(s1, s2, i+1, j, k), f(s1, s2, i, j+1, k));
        }
        else {
            return dp[i][j][k] = max(max(f(s1, s2, i+1, j, k), f(s1, s2, i, j+1, k)), 1 + f(s1, s2, i+1, j+1, k-1));
        }
    }
}

int main() {
    // problem link -> https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/?purpose=login&source=problem-page&update=google
    
    string text1 = "1234593459";
    string text2 = "5314209347";
    int k = 2;
    
    cout << dp[0][0][0] << endl;
    int largestLength = f(text1, text2, 0, 0, k);
    cout << largestLength << endl;
}