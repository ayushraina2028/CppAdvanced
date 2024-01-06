#include <iostream>
#include <vector>

using namespace std;

int canWeMake(int days, vector<int> bloomDay, int m, int k) {

    int count = 0;
    int maxCount = 0;
    bool flag = true; // for consecutive

    for(int i = 0;i < bloomDay.size(); i++) {
        if(flag and bloomDay[i] <= days) {
            count++;
            if(count == k) {
                maxCount++;
                count = 0;
                flag = false;
            }
        }

        else if(bloomDay[i] > days) {
            count = 0;
            flag = false;
        }

        else if(bloomDay[i] <= days and flag == false) {
            count++;
            if(count == k) {
                maxCount++;
                count = 0;
                flag = false;
            }
            flag = true;
        }
        
    }

    if(maxCount >= m) return true;
    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int max = bloomDay[0];

    for(int i = 1;i < bloomDay.size(); i++) {
        if(max < bloomDay[i]) max = bloomDay[i];
    }

    int lo = 1;
    int hi = max;
    int mid;
    bool flag = true;
    int minDays = max;
    while(lo <= hi) {
        mid = lo + (hi-lo)/2;

        if(canWeMake(mid,bloomDay,m,k)) {
            flag = false;
            minDays = mid;
            hi = mid-1;
        }

        else lo = mid+1;
    }

    if(flag) return -1;
    return minDays;
}

int main() {
    vector<int> bloomDay = {7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;

    int daysrequired = minDays(bloomDay,m,k);
    cout << daysrequired << endl;
}