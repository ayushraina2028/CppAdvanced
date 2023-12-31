#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    if(n==1) return "1";
    string str = countAndSay(n-1);

    string answer = "";

    int freq = 1;
    char ch = str[0];

    for(int i = 1;i < str.length(); i++) {
        char dh = str[i];
        if(ch==dh) freq++;
        else {
            answer += to_string(freq)+ch;
            freq = 1;
            ch = dh;
        }
    }

    // if repeating at last
    answer += to_string(freq) + ch;
    return answer;
}

int main() {
    int n = 4;
    cout << countAndSay(n) << endl;
}