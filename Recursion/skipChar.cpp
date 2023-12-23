#include <iostream>
#include <string>

using namespace std;

void removeChar(string str, string ans,int i,char ch) {
    if(i == str.length()) {
        cout << ans << endl;
        return;
    }
    if(str[i] == ch) return removeChar(str,ans,i+1,ch);
    else return removeChar(str,ans+str[i],i+1,ch);
}

int main() {
    string str = "ayush raina";
    removeChar(str,"",0,'i');
}