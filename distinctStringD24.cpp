#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> dp;


int f(string str, int i) {
    
    if(i == str.length()) return 0;
    else if(dp[i] != -1) return dp[i];
    int ways = 0;
    if(str[i] != str[i+1]) {
        ways = f(str, i+1); 
    }

    else {
        string str_temp = str;
        str_temp[i+1] = 'i';
        str[i] = 'i';
        ways = 1 + min(f(str, i+1), f(str_temp, i+1));
    }
    
    return dp[i] = ways;
}

int main() {
    string str = "aaabbbhhhhhhghdggggb";
    
    dp.clear();
    dp.resize(100004,-1);
    int ways = f(str, 0);
    cout << ways << endl;
}