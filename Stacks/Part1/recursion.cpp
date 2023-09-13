#include <iostream>
#include <stack>

using namespace std;

void displayUsingRecursion(stack <int> st) {
    if(st.empty()) return;
    cout << st.top() << " ";
    st.pop();
    displayUsingRecursion(st);
}

void reverseDisplayUsingRecursion(stack <int> st) {
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    reverseDisplayUsingRecursion(st);
    cout << x << " ";
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
    reverseDisplayUsingRecursion(st1);
    cout << endl;

}