#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
int maxArea = 1;

int maxSquare(vector<vector<int>>& nums, int i, int j, int num) {

    if(i == nums.size() or j == nums[0].size()) {
        return 0;
    }

    else if(dp[i][j] != -1) return dp[i][j];

    int next = maxSquare(nums, i, j+1, num);
    int down = maxSquare(nums, i+1, j, num);
    int diagonal = maxSquare(nums, i+1, j+1, num);

    int area = 1;
    if(nums[i][j] == num) {
        area = 1 + min(next, min(down, diagonal));
        maxArea = max(area, maxArea);
        return dp[i][j] = area;
    }

    return 0;
}

int main() {
    vector<vector<int>> matrix = {{0,0,1,0}, {0,0,1,1}, {0,1,1,1}, {0,1,1,1}};
    dp.clear();
    dp.resize(matrix.size(), vector<int> (matrix[0].size(), -1));
    maxSquare(matrix, 0, 0, 1);
    cout << "maximum area is: " << maxArea << endl;

    cout << "Here is the dp matrix formed: " << endl;
    for(auto row : dp) {
        for(auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}