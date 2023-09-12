#include <iostream>
#include <map>
using namespace std;

int main() {
    map <int, int> m;
    m[2] = 50;
    m[3] = 10;
    m[1] = 30;
    
    // -> ele.first comes in sorted order
    for(auto ele : m) {
        cout << ele.first << endl;
    }
    // -> ele.second comes in sorted order according to key value
    for(auto ele : m) {
        cout << ele.second << endl;
    }

    map <string, int> m1;
    m1["Ayush Raina"] = 8;
    m1["Vansh Dhar"] = 10;
    m1["Arnav"] = 40;

    // -> lexicographical order internally
    
    for (auto ele : m1) {
        cout << ele.first << " ";
    }
    cout << endl;
}