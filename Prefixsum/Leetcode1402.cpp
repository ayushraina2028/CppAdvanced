#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

// easy problem
vector<vector<int>> dp;

int maxSatisfaction(vector<int>& satisfaction, int i, int time) {
    if(i == satisfaction.size()) return 0;
    else if(dp[i][time-1] != -1) return dp[i][time-1];

    int maxi = 0;
    maxi = max(satisfaction[i]*time + maxSatisfaction(satisfaction,i+1,time+1), maxSatisfaction(satisfaction,i+1,time));

    return dp[i][time-1] = maxi;
}

int main() {
    vector<int> satisfaction = {34,-27,-49,-6,65,70,72,-37,-57,92,-72,36,6,-91,18,61,77,-91,5,64,-16,5,20,-60,-94,-15,-23,-10,-61,27,89,38,46,57,33,94,-79,43,-67,-73,-39,72,-52,13,65,-82,26,69,67};
    sort(satisfaction.begin(), satisfaction.end());
    int time = 1;

    int n = satisfaction.size();
    dp.clear();
    dp.resize(n, vector<int> (n, -1));
    
    int maximum = maxSatisfaction (satisfaction, 0, 1);
    cout << maximum << endl;
}