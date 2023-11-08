#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> dp;

int main() {
    // bottom up solution for lcs
    // Problem Link -> https://atcoder.jp/contests/dp/tasks/dp_f
    dp.clear();
    dp.resize(3005, vector<int> (3005,-1));

    string text1;
    string text2;

    cin >> text1;
    cin >> text2;

    // grid calculation
    for(int i = text1.size()-1; i >= 0; i--) {
        for(int j = text2.size()-1; j >= 0; j--) {
            if(text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    // printing
    string::size_type i = 0;
    string::size_type j = 0;
    while(i <= text1.length() and j <= text2.length()) {

        if(dp[i][j] == -1) break;

        if(dp[i][j] == max(dp[i+1][j], dp[i][j+1])) {
            if(dp[i+1][j] > dp[i][j+1]) {
                i++;
            }
            else j++;
        }

        else if(dp[i][j] == 1 + dp[i+1][j+1]) {
            cout << text1[i];
            i++, j++;
        }
    }
    cout << endl;

    return dp[0][0];
}
