#include <iostream>
#include <stack>

using namespace std;

int main() {
    // -> reverse elements of a stack in same stack
    // -> we need to use 2 extra stacks for this

    // -> make 3 stacks
    stack <int> st1;
    stack <int> st2;
    stack <int> st3;

    // Push some elements
    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);
    st1.push(50);
    st1.push(60);
    st1.push(70);

    cout << st1.top() << endl;

    // st1 => st2
    while(!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
    }

    // st2 => st3
    while(!st2.empty()) {
        st3.push(st2.top());
        st2.pop();
    } 

    // st3 => st1
    while(!st3.empty()) {
        st1.push(st3.top());
        st3.pop();
    }

    cout << st1.top() << endl;


}