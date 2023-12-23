#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pp pair<int, int>
using namespace std;

// operator overloading
class compare {
public:
    bool operator()(pp a, pp b) {
        return a.first > b.first;
    }
};

vector<vector<int>> merge(vector<vector<int>> intervals) {
    priority_queue<pp, vector<pp>, compare> pqueue;
    vector<vector<int>> answer;

    // push to pqueue
    for(auto row : intervals) {
        pqueue.push({row[0], row[1]});
    }

    while(!pqueue.empty()) {
        pp head = pqueue.top();
        pqueue.pop();
        

        pp secondhead = {-1, -1};
        if(!pqueue.empty()) {
            secondhead = pqueue.top();
            pqueue.pop();

            if(head.second < secondhead.first) {
                answer.push_back({head.first, head.second});
                pqueue.push(secondhead);
            }

            else {
                pp newhead = {min(head.first, secondhead.first), max(head.second, secondhead.second)};
                pqueue.push(newhead);
            }
        }

        else {
            answer.push_back({head.first, head.second});
        }
    }

    return answer;
}


int main() {
    vector<vector<int>> intervals= {{1,4} ,{4,5}, {2,6}, {15,18}};
    vector<vector<int>> mergedIntervals = merge(intervals);

    for(auto row : mergedIntervals) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}