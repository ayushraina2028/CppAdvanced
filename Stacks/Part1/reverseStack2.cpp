#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    // -> make 3 stacks
    stack <int> st1;
    vector <int> helper;

    // Push some elements
    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);
    st1.push(50);
    st1.push(60);
    st1.push(70);

    cout << st1.top() << endl;

    // A better approach
    while(!st1.empty()) {
        helper.push_back(st1.top());
        st1.pop();
    }

    for(int i = 0; i < helper.size();i++) {
        st1.push(helper[i]);
    }

    cout << st1.top() << endl;
}