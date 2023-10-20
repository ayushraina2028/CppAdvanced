#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> dp;

int f(string &s1, string &s2, int i, int j) {
    if(i == s1.length() || j == s2.length()) {
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    // -> recurrence relation
    if(s1[i] == s2[j]) {
        return dp[i][j] = 1 + f(s1,s2,i+1,j+1);
    }
    else{
        return dp[i][j] = max(f(s1,s2,i+1,j), f(s1,s2,i,j+1));
    }
}

int main() {
    // Leetcode 1143
    string text1 = "abracadabra";
    string text2 = "avadakedavra";

    dp.clear();
    dp.resize(1005,vector<int> (1005,-1));

    int largestLength = f(text1, text2, 0, 0);
    cout << largestLength << endl;
}   