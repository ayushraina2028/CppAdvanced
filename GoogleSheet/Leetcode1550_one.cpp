#include <bits/stdc++.h>
using namespace std;

bool threeConsecutiveOnes2(vector<int> arr) {
    if(arr.size() < 3) return false;

    for(int i = 0;i < arr.size()-1; i++) {
        if((arr[i] % 2 != 0) and (arr[i+1] % 2 != 0) and (arr[i+2] % 2 != 0)) return true;
    }

    return false;
}

bool threeConsecutiveOnes(vector<int> arr) {
    if (arr.size() < 3) return false;

    int answer = 0;
    for(int i = 0;i < arr.size(); i++) {
        if(arr[i] % 2 != 0) answer++;
        else answer = 0;

        if(answer == 3) return true;
    }

    return false;
}

int main() {
    vector<int> arr = {2,6,4,1};
    bool answer = threeConsecutiveOnes(arr);
    cout << answer << endl;
}