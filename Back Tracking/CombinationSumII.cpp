#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void f(vector<int>& candidates, int target, int idx, vector<vector<int>>& answer, vector<int>& subset) {
    if(target == 0) {
        answer.push_back(subset);
        return;
    }

    else if(idx == candidates.size()) return;

    if(candidates[idx] <= target) {
        subset.push_back(candidates[idx]);
        f(candidates, target-candidates[idx], idx+1, answer, subset);
        subset.pop_back();
    }

    // call for not pick
    int new_idx = idx+1;
    while(new_idx < candidates.size() and candidates[new_idx] == candidates[new_idx-1]) new_idx++;
    f(candidates,target,new_idx,answer,subset);
    
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int> subset;

    f(candidates,target,0,answer,subset);

    return answer;
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    sort(candidates.begin(), candidates.end());
    vector<vector<int>> answer = combinationSum2(candidates,target);

    for(auto row : answer) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }
}   