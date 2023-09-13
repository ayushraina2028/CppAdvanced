#include <iostream>
#include <climits>
using namespace std;

class Stack{

    // Required Things while initializing the stack
    int capacity;
    int* arr;
    int top;

public:

    // Initializing the stack
    Stack(int n) {
        this -> capacity = n;
        this -> arr = new int[n];
        this -> top = -1;
    }

    // Pushing the value with overflow check
    void push(int data) {
        if(this -> top == this -> capacity-1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        this -> top++;
        this -> arr[this->top] = data;
    }

    // Pop function with underflow check condition
    void pop() {
        if(this->top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        this->top--;
    }

    // getTop() function
    int getTop() {
        if(this->top == -1) {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        else if(this->top == this->capacity) {
            cout << "Stack Overflow" << endl;
            return INT_MAX;
        }
        else {
            return this->arr[this->top];
        }
    }

    // isEmpty()
    bool isEmpty() {
        return this->top == -1;
    }

    // size()
    int size() {
        return this->top +1;
    }

    // isFull()
    bool isFull() {
        return this->top == this->capacity-1;
    }

};


int main() {

    // Checks
    Stack st(5);
    st.push(1);
    st.push(3);
    cout << st.getTop() << endl;
    st.push(5);
    st.pop();
    cout << st.getTop() << endl;
    cout << st.isEmpty() << endl;
    cout << st.size() << endl;
    st.pop();
    st.pop();
    cout << st.isEmpty() << endl;


}