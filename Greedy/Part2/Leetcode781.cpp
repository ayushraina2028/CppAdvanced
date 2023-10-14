#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int minimumRabbits(vector<int> answers) {
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    unordered_map<int, int> map;
    int count = 0;

    for(auto element : answers) {
        map[element]++;
    }

    for(auto element : map) {
        pq.push({element.first, element.second});
    }

    while(!pq.empty()) {
        
        pair<int, int> p = pq.top();
        pq.pop();
        cout << p.first << " " << p.second << endl;

        if(p.first == 0) {
            count += p.second;
            cout << "Count is: " << count << endl;
        }
        else if(p.second == 1) {
            count += p.first + 1;
            cout << "Count is: " << count << endl;
        }
        else if(p.second > 1) {
            if(p.first > p.second || p.first == p.second || p.first == p.second-1) {
                count += p.first+1;
                cout << "Count is: " << count << endl;
            }
            else {
                count += p.first+1;
                pq.push({p.first, p.second-p.first-1});
                cout << "Count is: " << count << endl;
            }
        }
    }

    return count;
}

int main() {
    vector<int> answers = {1,0,1,0,0};
    cout << minimumRabbits(answers) << endl;
}