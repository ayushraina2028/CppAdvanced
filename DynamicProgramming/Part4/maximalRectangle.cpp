#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int largestRectangle(vector<int> nums, int bit) {
    int area = 0;

    vector<int> prevSmaller;
    vector<int> nextSmaller;

    for(int i = 0;i < nums.size(); i++) {
        int prev = -1;
        for(int j = i-1;j >= 0; j--) {
            if(nums[j] < nums[i]) {
                prev = j;
                break;
            }
        }
        prevSmaller.push_back(prev);
    }

    for(int i = 0;i < nums.size(); i++) {
        int nextIdx = nums.size();
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[j] < nums[i]) {
                nextIdx = j;
                break;
            }
        }
        nextSmaller.push_back(nextIdx);
    }

    int maxArea = 0;
    for(int k = 0; k < nums.size(); k++) {
        area = nums[k];
        area *= nextSmaller[k] - prevSmaller[k] - 1;
        maxArea = max(area, maxArea);
    }
    for(auto ele : prevSmaller) {
        cout << ele << " ";
    }
    cout << endl;
    return maxArea;
}

int main() {
    vector<vector<int>> matrix = {{1,0,1,0,1}, {1,1,1,1,1}, {1,1,1,0,0}, {1,1,1,1,1}};
    int n = matrix.size();
    int m = matrix[0].size();
    cout << n << " " << m << endl;

    dp.clear();
    dp.resize(n, vector<int> (m,0));

    for(int i = 0;i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0) {
                dp[i][j] = matrix[i][j];
            }
            else if(matrix[i][j] == 1){
                dp[i][j] = dp[i-1][j] + matrix[i][j];
            }
        }
    }

    // check our dp vector
    for(auto row : dp) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    // now iterate
    int maxArea = 0;
    for(auto row : dp) {
        int area = largestRectangle(row,1);
        maxArea = max(area, maxArea);
    }

    cout << maxArea << endl;
}