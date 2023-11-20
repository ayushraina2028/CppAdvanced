#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    // Initialize with default values
    vector <int> nextSmallerElement(n,-1);
    vector <int> prevSmallerElement(n,n);

    stack <int> st;
    st.push(n-1);
    nextSmallerElement[n-1] = n;

    for(int i = n-2;i >= 0;i--) {

        while(st.size() > 0 && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if(st.size() == 0) {
            nextSmallerElement[i] = n;
            st.push(i);
            continue;
        }

        nextSmallerElement[i] = st.top();
        st.push(i);
    }

    stack <int> st2;
    st2.push(0);
    prevSmallerElement[0] = -1;

    for(int i = 1; i < n;i++) {

        while(st2.size() > 0 && heights[st2.top()] >= heights[i]) {
            st2.pop();
        }

        if(st2.size() == 0) {
            prevSmallerElement[i] = -1;
            st2.push(i);
            continue;
        }

        prevSmallerElement[i] = st2.top();
        st2.push(i);

    }

    int maxArea = 0;
    for(int i = 0;i < heights.size(); i++) {

        if(prevSmallerElement[i] == -1) {
            maxArea = max(maxArea, heights[i]*nextSmallerElement[i]);
        }
        else {
            maxArea = max(maxArea, heights[i]*(nextSmallerElement[i]
            -prevSmallerElement[i]-1));
        }
    }
    for(auto ele : prevSmallerElement) {
        cout << ele << " ";
    }
    cout << endl;
    return maxArea;
}

int main() {

    vector<vector<int>> matrix = {{1,0,1,0,0}, {1,0,1,1,1}, {1,1,1,1,1}, {1,0,0,1,0}};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp;
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

    int maxArea = 0;
    for(auto row : dp) {
        int area = largestRectangleArea(row);
        maxArea = max(area,maxArea);
    }
    
    cout << maxArea << endl;
}
