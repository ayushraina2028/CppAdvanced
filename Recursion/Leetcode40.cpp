#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// to run this, copy below functions and submit on leetcode.
void combinations(vector<int>& candidates, int target, vector<vector<int>>& answer, vector<int> v, int index) {
    if(target == 0) {
        answer.push_back(v);
        return;
    }
    else if(target < 0) return;

    for(int i = index; i < candidates.size(); i++) {
        
        // One more Line for Combination Sum II
        if(i > index and candidates[i] == candidates[i-1]) continue;

        v.push_back(candidates[i]);
        combinations(candidates, target-candidates[i], answer, v, i+1);
        v.pop_back();
    }

    return;
}

vector<vector<int>> combinationSumII(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int> v;
    sort(candidates.begin(), candidates.end());
    combinations(candidates,target,answer,v,0);
    return answer;
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> answer = combinationSumII(candidates, target);
    for(auto row : answer) {
        for(auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}