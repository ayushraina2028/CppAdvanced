#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    int m = queries.size();

    vector<int> answer(m,0);
    sort(nums.begin(), nums.end());

    // make prefix sum
    for(int i = 1;i < n; i++) {
        nums[i] += nums[i-1];
    }

    for(int i = 0;i < m; i++) {
        int maxlen = 0;
        int lo = 0;
        int hi = n-1;

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if(nums[mid] > queries[i]) hi = mid-1;
            else {
                maxlen = mid+1;
                lo = mid+1;
            }
        }
        answer[i] = maxlen;
    }


    return answer;
}

int main() {
    vector<int> nums = {4,5,2,1};
    vector<int> queries = {3,10,21};
    vector<int> answer = answerQueries(nums, queries);

    for(auto ans : answer) cout << ans << " ";
    cout << endl;
}