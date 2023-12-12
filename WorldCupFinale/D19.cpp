#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pp pair<int, int> 

vector<pp> whichBowler(vector<int> v, vector<int> query) {
    
    int max_query = 0;
    for(int ele : query) {
        if(max_query < ele) max_query = ele;
    }
    cout << max_query << endl;
    
    vector<pp> dp = {{-1,0}};

    bool flag = true;
    bool reversed = false;
    int curr_ele = 0;
    int curr_idx = 0;
    int temp = 0;
    
    while(curr_ele < max_query) {

        
        if(curr_idx == 0) {
            dp[curr_idx] = {v[temp]-1,temp};
            curr_idx++;
            temp++;
        }

        else if(temp % v.size() == 0 and temp != 0) {
            if(!reversed) {
                reversed = true;
            }
            else {
                reversed = false;
            }
            reverse(v.begin(), v.end());
            temp = 0;
        }

        

        else {
            curr_ele = dp[curr_idx-1].first + v[temp];
            if(reversed) {
                dp.push_back({curr_ele, v.size()-temp-1});
            }
            else {
                dp.push_back({curr_ele, temp});
            }
            
            curr_idx++;
            temp++;
        }

        
    }

    vector <int> answer;
    answer.resize(query.size());

    int x = 0;
    while(x < query.size()) {
        
        if(query[x] >= 0 and query[x] <= dp[0].first) {
            answer[x] = dp[0].second+1;
            x++;
        }
        else {
            for(int i = 1;i < dp.size();i++) {
                if(query[x] >= dp[i-1].first+1 and query[x] <= dp[i].first) {
                    answer[x] = dp[i].second+1;
                    x++;
                }
            }
        }
    }

    for(int ele : answer) {
        cout << ele << " ";
    }
    cout << endl;

    return dp;
}

int main() {
    vector<int> v = {8,23 ,20 ,11 ,13 ,7 ,3 ,9, 8, 6, 10, 18, 8 };
    vector<int> query = {60, 31, 50, 52, 86, 18, 4, 24, 18, 8, 1, 33, 8, 85, 34, 27, 84, 100, 75, 41, 2 ,19, 68 };

    vector<pp> answer = whichBowler(v, query);
    cout << "0 " << answer[0].first << " -> " << answer[0].second+1 << endl;

    for(int i = 1; i < answer.size(); i++) {
        cout << answer[i-1].first+1 << " " << answer[i].first << " -> " << answer[i].second+1 << endl;
    }
    cout << endl;
}