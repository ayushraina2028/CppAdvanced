#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

class Node{
public:
    int val;
    Node* next;

    // -> Constructor for node
    Node(int val) {
        this -> val = val;
        this -> next = NULL;
    }
};

class stack {

    // These can be kept private
    Node* head;
    int capacity;
    int currSize;

public:

    // Constructor for our stack
    stack(int c) {
        this -> capacity = c;
        this -> currSize = 0;
        this -> head = NULL;
    }

    // is Empty function
    bool isEmpty() {
        return this -> head == NULL;
    }

    // is Full Function
    bool isFull() {
        return this -> currSize == this -> capacity;
    }

    // push
    void push(int data) {

        // Base Case
        if(this -> currSize == this -> capacity) {
            cout << "Stack Overflow " << endl;
            return;
        }

        Node* node = new Node(data);
        node -> next = this -> head;
        this -> head = node;
        this -> currSize++;
    }

    // get top element
    int getTop() {

        // Base Case
        if(this -> head == NULL) {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }

        return this -> head -> val;
    }

    // pop() function
    void pop() {

        // Base Case
        if(this -> head == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }

        this -> head = this -> head -> next;
        this -> currSize--;
    }

    int size() {
        return this -> currSize;
    }
};

int main() {
    // Checks
    stack st(5);
    st.push(1);
    st.push(3);
    cout << st.getTop() << endl;
    st.push(5);
    cout << st.getTop() << endl;
    cout << st.isEmpty() << endl;
    cout << st.size() << endl;
    st.pop();
    cout << st.getTop() << endl;
    st.push(5);
    cout << st.getTop() << endl;
    st.pop();
    cout << st.isEmpty() << endl;


}

