#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pp pair<int, int>
using namespace std;

class compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {

    vector<vector<int>> answer;
    priority_queue<pp, vector<pp>, compare> pq;

    for(auto element : intervals) {
        pq.push({element[0], element[1]});
        // cout << element[0] << " " << element[1] << endl;
    }

    if(intervals.size()==1) return intervals;

    while(!pq.empty()) {
        pp topp = pq.top();
        pq.pop();

        cout << topp.first << " " << topp.second << endl;
        if(!pq.empty()) { 
            pp topp2 = pq.top();
            pq.pop();
            cout << topp2.first << " " << topp2.second << endl;

            if(topp.second < topp2.first) {
                cout << "pushed" << endl;
                answer.push_back({topp.first, topp.second});
                pq.push(topp2);
            }
            else if(topp.second >= topp2.first) {
                pq.push({min(topp.first, topp2.first), max(topp.second, topp2.second)});
            }
        }
        else {
            answer.push_back({topp.first, topp.second});
        }
    }

    return answer;
}   

int main() {
    vector <vector <int>> intervals = {{1,4}, {0,2}, {3,5}};
    
    vector<vector <int>> mergedIntervals = mergeIntervals(intervals);
    cout << endl;
    for(auto array : mergedIntervals) {
        for(auto element : array) {
            cout << element << " ";
        }
        cout << endl;
    }
}