#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    cout << st.size() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    cout << st.size() << endl;
    st.pop();
    cout << st.size() << endl;
    cout << st.top() << endl;

    // ->printing elements from stack
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl; // -> but out stack got empty
}