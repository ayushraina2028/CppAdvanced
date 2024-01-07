#include <bits/stdc++.h>
using namespace std;

long double minimizeDistance(vector<int>& stations, int k) {

    // O(k*n appoach), we clearly see by using priority_queue we will be able to optimise this further.

    int n = stations.size();
    vector<int> stationBetween(n-1,0);

    for(int gasStations = 1; gasStations <= k; gasStations++) {
        long double maxSection = -1;
        int index = -1;

        for(int i = 0;i < n-1; i++) {
            long double sectionDifference = (stations[i+1] - stations[i])/(long double)(stationBetween[i]+1);
            if(maxSection < sectionDifference) {
                maxSection = sectionDifference;
                index = i;
            }
        }

        stationBetween[index]++;
    }

    long double maxAnswer = -1;
    for(int i = 0;i < n-1; i++) {
        long double sectionDifference = (stations[i+1] - stations[i])/(long double)(stationBetween[i]+1);
        maxAnswer = max(maxAnswer,sectionDifference);
    }

    return maxAnswer;
}

int main() {
    vector<int> stations = {1,2,3,4,5};
    int k = 4;

    long double minimumdistance = minimizeDistance(stations, k);
    cout << minimumdistance << endl;
}