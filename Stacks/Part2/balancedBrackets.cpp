#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkBalance(string str) {
    stack <char> st;

    // -> odd length not possible
    if(str.length() % 2 != 0) return false;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            st.push(str[i]);
        }
        else {
            if(st.size()==0) return false;
            else {
                st.pop();
            }
        }
    }    

    if(st.size()==0) return true;

    return false;
}

int main() {
    string str = "()((()))";
    cout << checkBalance(str) << endl;
}