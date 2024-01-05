#include <iostream>
#include <vector>

using namespace std;

void f(vector<int>& candidates, int target, int idx, vector<vector<int>>& answer, vector<int>& subset) {
    if(target == 0) {
        answer.push_back(subset);
        return;
    }

    else if(idx == candidates.size()) return;

    if(candidates[idx] <= target) {
        subset.push_back(candidates[idx]);
        f(candidates, target-candidates[idx], idx, answer, subset);
        subset.pop_back();
    }

    // call for not pick
    f(candidates,target,idx+1,answer,subset);

    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int> subset;

    f(candidates,target,0,answer,subset);

    return answer;
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    vector<vector<int>> answer = combinationSum(candidates,target);

    for(auto row : answer) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }
}   