#include <iostream>
#include <stack>
using namespace std;

void display(stack <int> st) {
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void insertAt(int index, int val, stack <int>& st) {
    stack <int> helper;
    cout << st.size() << endl;
    int i = 0;
    int n = st.size();
    while(i < n-index) {
        helper.push(st.top());
        st.pop();
        i++;
    }
    st.push(val);
    while(!helper.empty()) {
        st.push(helper.top());
        helper.pop();
    }
}

int main() {
    stack <int> st;
    stack <int> helper;

    // Push some elements
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    insertAt(2,5,st);
    cout << st.size() << endl;

    display(st);

}