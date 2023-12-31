#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printSubsets(string str,string subset,int i, vector<string>& subsets) {
    if(i == str.length()) {
        subsets.push_back(subset);
        return;
    }
    
    // recursive calls
    printSubsets(str,subset+str[i],i+1,subsets);
    int len = subset.length();
    if(str[i] != subset[len-1]) printSubsets(str,subset,i+1,subsets);
    
}

int main() {
    string str = "abacca";
    vector<string> subsets;
    sort(str.begin(), str.end());

    printSubsets(str,"",0, subsets);

    for(auto string : subsets) {
        cout << string << " ";
    }
    cout << endl;
}