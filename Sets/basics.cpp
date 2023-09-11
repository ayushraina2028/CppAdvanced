#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // -> stores unique elements only
    // -> you can push back same elements again, but it will not be added internally

    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    // -> elements are stored in random order
    // -> hence for traversing in set we need to use for each loop

    for(int x : s) cout << x << " ";
    cout << endl;

    // size()
    s.insert(2);
    cout << s.size() << endl;

    // erase
    s.erase(2);
    for(int x : s) cout << x << " ";
    cout << endl;

    // -> find whether some element exists in set or not
    int target = 4;
    if(s.find(target) != s.end()) {  // -> means exists and s.find(target)==s.end() => means not exists
        cout << "Element Exists! " << endl;
    }
    else {
        cout << "Not Exists! " << endl;
    }

    
    // Leetcode 2442;
    // Leetcode 2744;
}
