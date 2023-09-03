#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    
    // By default we want to give null address to nodes
    Node(int n) {
        this->val = n;
        this->next = NULL;
    }
};

int main() {
    // 10 20 30 40
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    // -> forming linked list
    a.next = &b;
    b.next = &c;
    c.next = &d;
    
    // Print value of b
    // method 1
    cout << b.val << endl;

    // method 2
    Node* ptr = &b;
    cout << ptr->val << endl;

    // method 3
    cout << a.next->val << endl;

    // method 4
    cout << (*(a.next)).val << endl;

    // Print value of c
    cout << (b.next)->val << endl;
    cout << ((a.next)->next)->val << endl;

    // Print value of d
    cout << (a.next)->next->next->val << endl;
    cout << (*((*((*(a.next)).next)).next)).val << endl; // working fine

    cout << "print using for loop" << endl;
    
    Node temp = a;
    while(temp.next != NULL) {
        cout << temp.val << " ";
        temp = *(temp.next); // temp is now a copy of next node

        if(temp.next == NULL) {
            cout << temp.val << endl;
        }
    }
    
    
    
    
}