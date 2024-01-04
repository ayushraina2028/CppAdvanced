#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void permutations(string &input, int i) {

    if(i == input.size()-1) {
        cout << input << " ";
        return;
    }
    
    unordered_set<char> set;
    for(int index = i;index < input.size(); index++) {

        // In case of repeating elements
        if(set.find(input[index]) != set.end()) continue;
        else set.insert(input[index]);

        // swap to first;
        swap(input[index], input[i]);

        // make next call;
        permutations(input,i+1);

        // revert the swap while backtracking
        swap(input[index],input[i]);
    }
}

int main() {

    string str = "abca";
    cout << "Permutations of given string is -> ";
    permutations(str,0);
    cout << endl;

    return 0;
}