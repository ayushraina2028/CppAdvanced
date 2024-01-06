#include <iostream>
#include <vector>

using namespace std;

bool canWeEat(int speed, vector<int> piles, int hours) {
    long long int count = 0;
    int i = 0;
    while(i < piles.size()) {
        if(piles[i] < speed) {
            count++;
            i++;
        }
        else if(piles[i] > speed) {
            count += piles[i]/speed;
            if(piles[i] % speed != 0) count++;
            i++;
        }
        else {
            i++;
            count++;
        }
    }

    if(count <= hours) return true;
    return false;
}

int main() {
    vector<int> piles = {312884470};
    int hours = 312884469;

    int min = piles[0], max = piles[0];
    for(int i = 1;i < piles.size(); i++) {
        if(min > piles[i]) min = piles[i];
        if(max < piles[i]) max = piles[i];
    }

    cout << min << " " << max << endl;

    int lo = 1;
    int hi = max;

    int mid;
    int minSpeed = max;
    while(lo <= hi) {
        mid = lo + (hi-lo)/2;

        if(canWeEat(mid,piles,hours)) {
            minSpeed = mid;
            hi = mid-1;
        }

        else lo = mid+1;

    }


    cout << minSpeed << endl;
}