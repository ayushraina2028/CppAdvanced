#include <iostream>
#include <vector>

using namespace std;

// to run this, copy below functions and submit on leetcode.
void combinations(vector<int>& candidates, int target, vector<vector<int>>& answer, vector<int> v, int index) {
    if(target == 0) {
        answer.push_back(v);
        return;
    }
    else if(target < 0) return;

    for(int i = index; i < candidates.size(); i++) {

        v.push_back(candidates[i]);
        combinations(candidates, target-candidates[i], answer, v, i);
        v.pop_back();
    }

    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int> v;

    combinations(candidates,target,answer,v,0);
    return answer;
}

int main() {
    vector<int> candidates = {2,3,6,7,4};
    int target = 7;

    vector<vector<int>> answer = combinationSum(candidates, target);
    for(auto row : answer) {
        for(auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}