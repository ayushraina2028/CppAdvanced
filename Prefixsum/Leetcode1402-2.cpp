#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

// easy problem

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int n = satisfaction.size();
    vector<int> suffixSum = satisfaction;

    for(int i = n-2;i >= 0; i--) {
        suffixSum[i] = suffixSum[i] + suffixSum[i+1];
    }

    for(auto ele : suffixSum) cout << ele << " ";
    cout << endl;

    // find pivot index
    int idx = -1;

    for(int i = 0;i < n; i++) {
        if(suffixSum[i] >= 0) {
            idx = i;
            break;
        }
    }
    
    if(idx == -1) return 0;
    
    cout << idx << " " << endl;
    int time = 1;
    int maxi = 0;
    for(int i = idx; i < n; i++) {
        maxi += satisfaction[i]*time;
        time++;
    }

    return maxi;
}

int main() {
    vector<int> satisfaction = {-1,-8,0,5,-9};
    sort(satisfaction.begin(), satisfaction.end());
    int time = 1;
    
    int maximum = maxSatisfaction (satisfaction);
    cout << maximum << endl;
}