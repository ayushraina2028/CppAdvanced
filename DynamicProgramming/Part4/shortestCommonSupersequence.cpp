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

    if(i == A.length() || j == B.length()) {
        return 0;
    }
    else if(dp[i][j] != 0) return dp[i][j];

    if(A[i] == B[j]) {
        return dp[i][j] = 1 + f(A,B,i+1,j+1);
    }
    else {
        return dp[i][j] = max(f(A,B,i+1,j), f(A,B,i,j+1));
    }


}

void printShortestCommonSubsequence(string A, string B) {
    int i = 0;
    int j = 0;

    int n = A.size();
    int m = B.size();

    while(i != n and j != m) {

        if(dp[i][j] == max(dp[i+1][j], dp[i][j+1])) {
            if(dp[i+1][j] > dp[i][j+1]) {
                cout << A[i];
                i++;
            }
            else {
                cout << B[j];
                j++;
            }
        }

        else if(dp[i][j] == 1 + dp[i+1][j+1]) {
            cout << A[i];
            i++, j++;
        }
    }

    if(i == n and j != m) {
        while(j != m) {
            cout << B[j];
            j++;
        }
    }

    else if(i != n and j == m) {
        while(i != n) {
            cout << A[i];
            i++;
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
    printShortestCommonSubsequence(text_1,text_2);
    cout << endl;
}
