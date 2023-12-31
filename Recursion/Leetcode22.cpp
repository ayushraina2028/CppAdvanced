#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generate(vector<string>& answer, string str, int open, int close, int n) {
    if(close == n) {
        answer.push_back(str);
        return;
    }

    if(open < n) generate(answer, str + '(', open+1, close, n);
    if(close < open) generate(answer, str + ')', open, close+1, n);

    return;
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate(result,"", 0, 0, n);

    return result;
}

int main() {
    int n = 4;
    vector<string> parenthesis = generateParenthesis(n);
    for(auto s : parenthesis) cout << s << " ";
    cout << endl;
}