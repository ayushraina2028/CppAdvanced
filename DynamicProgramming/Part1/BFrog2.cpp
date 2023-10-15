#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> heights;
int n;
int k;

int minimumCostToReachEnd(int i) {

    if(i == n-1) {
        // we are at last stone so 0 cost from end->end
        return 0; 
    }

    int minCost = INT_MAX;

    // main search
    for(int j = 1;j <= k;j++) {
        if(i + j < n) {
            minCost = min(minCost, abs(heights[i+j] - heights[i]) + minimumCostToReachEnd(i+j));
        }
        else {
            break;
        }
    }

    return minCost;
}

int main() {
    cin >> n >> k;
    heights.clear();
    heights.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    // here also we have repeating subproblems that we will optimise in next part
    cout << minimumCostToReachEnd(0) << endl;
    return 0;
}