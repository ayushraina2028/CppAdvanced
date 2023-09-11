#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map <string, int> map;  // -> key value pairs

    // Pairs can be inserted into a unordered map
    // data can be put by using pair.first, and pair.second

    // -> direct add is not available in map
    pair <string, int> p1;
    p1.first = "ayush";
    p1.second = 78;

    map.insert(p1);

    pair <string, int> p2;
    p2.first = "arnav";
    p2.second = 46;

    map.insert(p2);

    // another way to insert (best way)
    map["Vansh"] = 23;

    map["Raina"] = 44;

    // Printing elements: -> auto us used to automatically detect the data type
    for(auto p: map) {
        cout << p.first << " " << p.second << endl;
    }

    // -> removing elements, need only key 
    map.erase("Raina");
    cout << endl;

    for(auto p: map) {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    // ->size
    cout << map.size() << endl;

    // in find() operation we find key and syntax is same
    

}