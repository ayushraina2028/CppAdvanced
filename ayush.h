#include <iostream>
#include <vector>

using namespace std;

void display(vector<vector<int>> vect) {
    for(auto row : vect) {
        for(auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}