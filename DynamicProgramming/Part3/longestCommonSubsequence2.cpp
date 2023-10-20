#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> dp;

int main() {
    // bottom up solution for lcs
    dp.clear();
    dp.resize(1005, vector<int> (1005,0));

    string text1 = "abracadabra";
    string text2 = "avadakedavra";

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
    cout << dp[0][0] << endl;
    return dp[0][0];
}
