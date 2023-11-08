#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

vector<vector<int>> dp;

int f(vector<int> &v, unordered_set<int> set, int i) {
    if(set.size() == 0) return 0;

    int minCost = INT_MAX;
    for(int idx : set) {

        unordered_set<int> temp = set;
        temp.erase(idx);
        minCost = min(minCost, abs(v[i] - v[idx]) + f(v, temp, idx));
        
    }

    return minCost;
}

int main() {
    //vector<int> v = {-53, 13, -82, -95, 99, 62, -42, 55, -4, 85, -28};
    vector<int> v = {4, 5, -2, 1};
    unordered_set<int> set;

    for(int i = 0; i < v.size(); i++) {
        set.insert(i);
    }

    int minCost = f(v,set,0);
    cout << minCost << endl;

    cout << endl;
}