#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> dp;

void display(vector<vector<int>> dp) {
    for(auto row : dp) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int f(string A, string B, int i, int j) {

    for(int i = A.size()-1; i >= 0; i--) {
        for(int j = B.size()-1; j >= 0; j--) {
            if(A[i] == B[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    
    return dp[0][0];
}

void printLCS(string A, string B) {
    int i = 0;
    int j = 0;

    int n = A.size();
    int m = B.size();

    while(i <= n and j <= n) {

        if(dp[i][j] == 0) {
            break;
        }

        if(dp[i][j] == max(dp[i+1][j], dp[i][j+1])) {
            if(dp[i+1][j] > dp[i][j+1]) {
                i++;
            }
            else j++;
        }

        else if(dp[i][j] == 1 + dp[i+1][j+1]) {
            cout << A[i];
            i++, j++;
        }

    }
}

int main() {
    string text_1 = "bbcbcaabc";
    string text_2 = "cacaabaaaa";

    int n = text_1.length();
    int m = text_2.length();

    dp.clear();
    dp.resize(n+1, vector<int> (m+1,0));

    int lengthofLCS = f(text_1, text_2, 0, 0);
    cout << lengthofLCS << endl;

    display(dp);
    printLCS(text_1,text_2);
    cout << endl;
}

/*
s1 = abracadabra
s2 = avadakedavra
*/
// ans -> aaadara