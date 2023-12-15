#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1,2,4,5,3,2,7,6};
    int n = arr.size();

    vector<int> prefixSum(n, 0);
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        prefixSum[i] = sum;
    }

    for(auto ele : prefixSum) {
        cout << ele << " ";
    }
    cout << endl;


    // method 2
    for(int i = 1; i < n; i++) {
        arr[i] += arr[i-1];
    }

    for(auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;


    // now sum of a[i] -> a[j] = prefix[j] - prefix[i-1];
}