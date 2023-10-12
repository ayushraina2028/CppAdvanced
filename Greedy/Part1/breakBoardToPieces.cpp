#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int a,const int b) {
    return a > b;
}

int minCostToBreakGrid(int n, int m, vector<int> horizontal_cost, vector<int> vertical_cost) {

    int minCost = 0;

    sort(horizontal_cost.begin(), horizontal_cost.end(), compare);
    sort(vertical_cost.begin(), vertical_cost.end(), compare);

    for(auto element : horizontal_cost) cout << element << " ";
    cout << endl;
    for(auto element : vertical_cost) cout << element << " ";
    cout << endl;

    int horizontal_pieces = 1;
    int vertical_pieces = 1;

    int horizontal_pointer = 0;
    int vertical_pointer = 0;

    while(horizontal_pointer < vertical_cost.size() and vertical_pointer < horizontal_cost.size()) {

        if(horizontal_cost[vertical_pointer] < vertical_cost[horizontal_pointer]) {
            minCost += vertical_cost[horizontal_pointer]*vertical_pieces;
            horizontal_pointer++;
            horizontal_pieces++;
        }
        else {
            minCost += horizontal_cost[vertical_pointer]*horizontal_pieces;
            vertical_pointer++;
            vertical_pieces++;
        }
    }

    // if some pointer ends early
    while(horizontal_pointer < vertical_cost.size()) {
        minCost += vertical_cost[horizontal_pointer]*vertical_pieces;
        horizontal_pointer++;
        horizontal_pieces++;
    }

    while(vertical_pointer < horizontal_cost.size()) {
        minCost += horizontal_cost[vertical_pointer]*horizontal_pieces;
        vertical_pointer++;
        vertical_pieces++;
    }

    return minCost;
}

int main() {
    int n = 4, m = 6;
    vector<int> horizontal = {4,1,2};
    vector<int> vertical = {2,1,3,1,4};
    cout << minCostToBreakGrid(n, m, horizontal, vertical) << endl;
}