#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void helper(string str, int n, int k,string help, string& answer) {
    if(n==1) {
        help += str;
        answer = help;
        return;
    }
    else if(k==0) {
        reverse(str.begin(), str.end());
        help += str;
        answer = help;
        return;
    }

    int fact = 1;
    for(int i = 2;i < n; i++) {
        fact *= i;
    }

    int index = k/fact;
    if(k % fact == 0) index--;

    string left = str.substr(0,index);
    string right = str.substr(index+1);

    if(k > fact) return helper(left+right,n-1,k % fact,help+str[index],answer);
    else return helper(left+right,n-1,k,help+str[index],answer);
}

string getPermutation(int n, int k) {
    string str = "";
    for(int i = 1;i <= n; i++) {
        str += to_string(i);
    }

    string ans = "";
    helper(str,n,k,"",ans);
    return ans;
}

int main() {
    int n = 4, k = 13;
    string kthPermutation = getPermutation(n,k);
    cout << "Permutation " << k << " is -> " << kthPermutation << endl;
}