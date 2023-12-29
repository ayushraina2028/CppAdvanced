#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void display(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

void displayReverse(ListNode* tail) {
    while(tail) {
        cout << tail->val << " ";
        tail = tail->prev;
    }
    cout << endl;
    return;
}

void displayRec(ListNode* head) {
    if(head == NULL) return;
    cout << head -> val << " ";
    displayRec(head -> next);
}

void displayRecReverse(ListNode* head) {
    if(head == NULL) return;
    displayRec(head -> next);
    cout << head -> val << " ";
}

int main() {
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(20);
    ListNode* c = new ListNode(30);
    ListNode* d = new ListNode(40);
    ListNode* e = new ListNode(50);

    // connecting
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    displayReverse(d);
}