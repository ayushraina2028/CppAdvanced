#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

string repeatLimitedString(string s, int repeatLimit) {
    // first we make a frequency map
    unordered_map <char, int> map;
    for(auto str : s) {
        map[str]++;
    }

    // priority_queue for pair <char, int>
    // char will be compared, max Heap.
    priority_queue< pair<char, int> > pq;
    for(auto element : map) {
        pq.push({element.first, element.second});

        // other way is pq.push(element) --> think why ?
    }

    string answer = "";

    // main work
    while(!pq.empty()) {
        pair <char, int> largest = pq.top();
        pq.pop();
        int len = min(largest.second, repeatLimit);
        for(int i = 0; i < len; i++) {
            answer += largest.first;
        }

        pair <char, int> secondLargest;

        // time for next largest
        if(largest.second - len > 0) {
            if(!pq.empty()) {
                secondLargest = pq.top();
                pq.pop();
                answer += secondLargest.first;
            }
            else {
                return answer;
            }

            // pushing back remaining ones
            if(secondLargest.second-1 > 0) {
                pq.push({secondLargest.first, secondLargest.second-1});
            }

            // if we are in this if condition means we have more chars of largest one so push bck
            pq.push({largest.first, largest.second-len});
        }

    }

    return answer;

}

int main() {
    string s = "aababab";
    int repeatLimit = 2;
    string answer = repeatLimitedString(s, repeatLimit);
    cout << answer << endl;
}