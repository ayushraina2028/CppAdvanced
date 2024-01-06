#include <iostream>
#include <vector>

using namespace std;

bool canWeShip(int capacity, vector<int> weights, int days) {
    int days_required = 1;
    int curr_capacity = capacity;

    int i = 0;
    while(i < weights.size()) {
        if(weights[i] <= curr_capacity) {
            curr_capacity -= weights[i];
            i++;
        }

        else if(weights[i] > curr_capacity) {
            
            days_required++;
            curr_capacity = capacity;

            if(weights[i] > curr_capacity) return false;
        }
    }

    if(days_required <= days) return true;
    else return false;
}

int shipWithinDays(vector<int> weights, int days) {
    int maxi = weights[0];

    for(int i = 1;i < weights.size(); i++) {
        maxi += weights[i];
    }


    int lo = 1;
    int hi = maxi;

    int mid;
    int minCapacity = maxi;

    while(lo <= hi) {
        mid = lo + (hi-lo)/2;

        if(canWeShip(mid,weights,days)) {
            minCapacity = mid;
            hi = mid-1;
        }
        else lo = mid+1;

    }

    return minCapacity;
}

int main() {
    vector <int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    int minCapacity = shipWithinDays(weights,days);
    cout << minCapacity << endl;
}