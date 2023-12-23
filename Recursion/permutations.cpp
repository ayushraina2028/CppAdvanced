#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void generatePermutations(string str, string help, vector<string>& permutations, int i) {
    int n = str.length();
    
    if(str == "") {
        permutations.push_back(help);
        return;
    }

    for(int j = 0; j < n; j++) {
        string l = str.substr(0,j);
        string r = str.substr(j+1);
        generatePermutations(l+r,help+str[j],permutations,i+1);
    }
}   

int main() {
    string str = "abcd";
    vector<string> subsets;

    generatePermutations(str,"",subsets,0);

    cout << "Your required Permutations -> ";
    for(auto string : subsets) {
        cout << string << " ";
    }
    cout << endl;
}