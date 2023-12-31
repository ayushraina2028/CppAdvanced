#include <iostream>
#include <string>

using namespace std;

void isPalindrome(string str, string& help, int i) {

    if(i == str.size()-1) {
        help += str[i];
        return;
    }

    isPalindrome(str, help, i+1);   
    help += str[i];
    return;
}

bool isPalindromeII(string str, int i, int j) {
    if(i > j) return true;
    else if(str[i] != str[j]) return false;

    else return isPalindromeII(str,i+1,j-1);
}

int main() {
    string str = "abcdcba";
    string revr = "";
    isPalindrome(str,revr,0);

    cout << revr << endl;
    cout << (str == revr) << endl;

    cout << isPalindromeII(str,0,str.length()-1) << endl;
}