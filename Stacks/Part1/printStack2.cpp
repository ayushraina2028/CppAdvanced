#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st1;
    stack<int> st2;

    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);
    st1.push(50);
    st1.push(60);
    st1.push(70);

    // -> normal print
    while(!st1.empty()) {
        cout << st1.top() << " ";
        st2.push(st1.top());
        st1.pop();
    }
    
    cout << endl;

    // -> restoring elements
    while(!st2.empty()) {
        st1.push(st2.top());
        st2.pop();
    }

    // -> Elements restored successfully
    cout << st1.top() << endl;

    

}