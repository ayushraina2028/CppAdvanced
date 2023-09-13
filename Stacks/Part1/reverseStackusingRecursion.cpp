#include <iostream>
#include <stack>

using namespace std;

void displayUsingRecursion(stack <int> st) {
    if(st.empty()) return;
    cout << st.top() << " ";
    st.pop();
    displayUsingRecursion(st);
}

void pushAtBottom(stack <int>& st, int val) {
    if(st.empty()) {
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottom(st,val);
    st.push(x);
}

void reverseStack(stack<int>& st) {
    if(st.size()==1) {
        return;
    }
    int x = st.top();
    st.pop();
    reverseStack(st);
    pushAtBottom(st,x);

}

int main() {
    stack<int> st1;

    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);
    st1.push(50);
    st1.push(60);
    st1.push(70);

    cout << "Display Using Recursion: ";
    displayUsingRecursion(st1);
    cout << endl;

    cout << "Reverse using Recursion: ";
    reverseStack(st1);
    displayUsingRecursion(st1);
    cout << endl;
}