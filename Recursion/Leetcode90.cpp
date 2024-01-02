#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void generateSubsets(vector<vector<int>>& answer,vector<int> v,vector<int>& nums,int i) {
    if(i == nums.size()) {
        answer.push_back(v);
        return;
    }
    
    v.push_back(nums[i]);
    generateSubsets(answer,v,nums,i+1);
    v.pop_back();

    //perfect
    int n = v.size();
    if(n > 0 and v[n-1] != nums[i]) generateSubsets(answer,v,nums,i+1);
    else if(n==0) generateSubsets(answer,v,nums,i+1);
    return;
}

// perfect code.
void generateSubsetsII(vector<vector<int>>& answer, vector<int> v, vector<int>& nums,int index) {

    answer.push_back(v);
    for(int i = index; i < nums.size(); i++) {
       

        v.push_back(nums[i]);
        generateSubsetsII(answer,v,nums,i+1);
        v.pop_back();

    }

    return;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> subsets;
    vector<int> v;

    sort(nums.begin(), nums.end());

    generateSubsetsII(subsets,v,nums,0);

    for(auto row : subsets) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }
    cout << endl;
}