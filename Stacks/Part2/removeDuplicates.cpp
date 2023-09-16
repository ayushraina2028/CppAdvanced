#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeDuplicates(string str) {
    stack<char> st;
    string ans = "";
    st.push(str[0]);
    ans.push_back(str[0]);
    for(int i = 1;i < str.length(); i++) {
        if(str[i] == st.top()) {
            continue;
        }
        else{
            st.push(str[i]);
            ans.push_back(str[i]);
        }
    }

    return ans;
}

int main() {
    string str = "aaabbccdeeeeeedaaabfffgg";
    string ans = removeDuplicates(str);
    cout << ans << endl;
}