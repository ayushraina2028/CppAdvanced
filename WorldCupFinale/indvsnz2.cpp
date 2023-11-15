#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<long long int>> dp;

long long int f(vector<int>& a, int i, int j, int k,int power) {
    if(k == 0) return 0;
    long long int maxScore = 0;

    if(dp[i][j] != -1) return dp[i][j];

    maxScore += max(pow(2,power)*a[i] + f(a, i+1, j, k-1, power+1), pow(2,power)*a[j] + f(a, i, j-1, k-1, power+1));
    return dp[i][j] = maxScore;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 0;i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    int i = 0;
    int j = a.size()-1;
    dp.clear();
    dp.resize(1005, vector<long long int> (1005,-1));
    long long int maxScore = f(a,i,j,k,0);
    cout << maxScore  << endl;
}