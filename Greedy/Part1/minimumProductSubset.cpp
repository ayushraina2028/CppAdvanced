#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minProductSubset(vector <int> arr) {
    
    int zero_count = 0, negative_count = 0, positive_count = 0, positive_product = 1, negative_product = 1, largestNegative = INT_MIN;
    
    for(auto element : arr) {
        if(element == 0) zero_count++;
        else if(element < 0) {
            negative_count++;
            negative_product *= element;
            largestNegative = max(largestNegative, element);
        }
        else {
            positive_count++;
            positive_product *= element;
        }
    }

    
    if(negative_count == 0) {
        if(zero_count == 0) {
            auto iterator = min_element(arr.begin(), arr.end());
            return *iterator;
        }
        else{
            return 0;
        }
    }

    else {
        if(negative_count % 2 != 0) {
            // odd number of negatives
            return negative_product*positive_product;
        }
        else {
            // even number of negatives
            return (negative_product/largestNegative)*positive_product;
        }
    }

}

int main() {
    // kind of minimum product sub array but here we need product of subset(min)
    vector <int> v = {-2, -3, 1, 4, -2};
    cout << minProductSubset(v) << endl;

}