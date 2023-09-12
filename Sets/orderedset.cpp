#include <iostream>
#include <set>
#include <map>

using namespace std;
int main() {
    set <int> s;
    s.insert(9);
    s.insert(7);
    s.insert(1);

    // -> are printed in ascending order
    // Here operations take O(log n) in insertion deletion etc 
    for(auto ele : s) {
        cout << ele << endl;
    }
}