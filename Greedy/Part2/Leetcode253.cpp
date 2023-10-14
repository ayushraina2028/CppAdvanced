#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int minimumMeetingRooms(vector<vector<int>> intervals) {
    
    vector<int> start_time;
    vector<int> end_time;

    // check
    for(auto a : intervals) {
        start_time.push_back(a[0]);
        end_time.push_back(a[1]);
    }

    sort(start_time.begin(), start_time.end());
    sort(end_time.begin(), end_time.end());

    for(int i = 0;i < intervals.size(); i++) {
        cout << start_time[i] << " " << end_time[i] << endl;
    }

    int i = 0;
    int j = 0;
    int answer = 0;
    int rooms = 0;

    while(i < start_time.size() and j < start_time.size()) {
        if(start_time[i] < end_time[j]) {
            // some meeting is already is going
            rooms++;
            i++;
        }
        else if(start_time[i]>end_time[j]) {
            // some meeting is finished
            rooms--; // this is rooms in use at that particular time.
            j++;
        }
        else {
            // meeting is just finished and new meeting is started.
            i++;
            j++;
        }
        answer = max(answer,rooms);
    }

    return answer;
}

int main() {
    vector <vector <int>> intervals = {{1,10}, {2,7}, {8,12}, {3,19},{10,20}, {11,30}};
    int required_rooms = minimumMeetingRooms(intervals);
    cout << required_rooms << endl;
}