#include <iostream>
#include <vector>
using namespace std;

void generatepermutations(vector<int>& nums, int i, vector<vector<int>>& answer) {
    if(i == nums.size()-1) {
        answer.push_back(nums);
        return;
    }

    for(int index = i;index < nums.size(); index++) {

        swap(nums[i], nums[index]);
        generatepermutations(nums,i+1,answer);
        swap(nums[i], nums[index]);

    }

    return;
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answer;

    generatepermutations(nums,0,answer);

    return answer;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> permutations = permute(nums);

    for(auto row : permutations) {
        for(auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}