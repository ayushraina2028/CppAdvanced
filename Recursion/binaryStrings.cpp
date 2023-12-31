// generate all binary strings of length n without consecutive ones
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// my code
void binaryStrings(int n, vector<string>& strings, string str, int i, bool flag) {
    if(i==n) {
        strings.push_back(str);
        return;
    }

    if(flag) {
        str += '0';
        binaryStrings(n,strings,str,i+1,true);
        str.pop_back();
        str += '1';
        binaryStrings(n,strings,str,i+1,false);
    }
    else {
        str += '0';
        binaryStrings(n,strings,str,i+1,true);
    }

    return;
}

// solution code
void generate(int n, string s) {
    // base case
    if(s.length()==n) {
        cout << s << " ";
        return;
    }

    
    generate(n,s+'0');
    if(s.size() == 0 or s[s.size()-1] == '0') generate(n,s+'1');
}

int main() {
    int n = 5;
    vector<string> strings;
    binaryStrings(n, strings, "", 0, true);

    for(auto s : strings) cout << s << " ";
    cout << endl;

    generate(n,"");
    cout << endl;
}