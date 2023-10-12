#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        // sort accoring to profit
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int units = 0;

        // check 
        for(auto ele : boxTypes) {
            for(auto el : ele) {
                cout << el << " ";
            }
            cout << endl;
        }

        for(auto array : boxTypes) {
            if(array[0] < truckSize) {
                units += array[0]*array[1];
                truckSize -= array[0];
            }
            else {
                units += truckSize*array[1];
                truckSize = 0;
            }
        }
        cout << units << endl;
        return units;
    }
};

int main() {

    // in this problem consider units as profits and
    // this a application of fractional knapsack
    return 0;
}