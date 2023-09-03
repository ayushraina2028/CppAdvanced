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

void display(Node* head){
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int size(Node* head) {
    Node* temp = head;
    int n = 0;
    while(temp != NULL) {
        cout << temp->val << " ";
        n++;
        temp = temp->next;
    }
    cout << endl;
    return n;
}

void displayUsingRecursion(Node* head) {
    if(head == NULL) {
        cout << endl;
        return;
    }
    cout << head->val << " ";
    displayUsingRecursion(head->next);
}

void displayReverse(Node* head) {
    if(head == NULL) {
        return;
    }
    displayReverse(head->next);
    cout << head->val << " ";
}

void insertAtEnd(Node* head,int val) {
    Node* newNode = new Node(val);
    while(head->next != NULL) head = head->next;
    head->next = newNode;
}


int main() {

    // We are storing addresses of nodes
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    // Linking the list
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // Now traversing becomes easy due to use of pointers
    Node* temp = a;
    while(temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;

    // print d
    cout << a->next->next->next->val << endl;

    // printing by passing to a function
    display(a);

    // Finding Size
    cout << size(a) << endl;

    // print using recursion
    displayUsingRecursion(a);

    // print in reverse order
    displayReverse(a);
    cout << endl;

    // Here insertion at end takes O(n) time
    insertAtEnd(a,60);
    display(a);

}