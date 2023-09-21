#include <iostream>
#include <vector>
using namespace std;

int main() {
    // bruteforce solution
    vector <int> arr1 = {5,1,3,0,4,9,6};
    int count = 0;
    for(int i = 0;i < arr1.size()-1;i++) {
        for(int j = i+1;j < arr1.size();j++) {
            if(i < j && arr1[i] > arr1[j]) {
                count++;
            }
        }
    }

    cout << "No of Inversions: " << count << endl;
}