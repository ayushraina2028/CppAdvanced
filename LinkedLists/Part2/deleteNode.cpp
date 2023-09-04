#include <iostream>
using namespace std;

class Node{
public: 
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void display(Node* head) {
    while(head->next != NULL) {
        cout << head->val << " ";
        head = head->next;

        if(head->next == NULL) cout << head->val << endl;
    }
}

Node* deleteNode(Node* head,Node* targetNode) {

    if(head == targetNode) {
        head = head->next;
        return head;
    }

    Node* temp = head;
    while(temp->next != targetNode) temp = temp->next;
    temp->next = temp->next->next;
    return head;
}

Node* deleteValue(Node* head, int target) {
    if(head->val == target) {
        head = head->next;
        return head;
    }

    Node* temp = head;
    while(temp->next->val != target) temp = temp->next;
    temp->next = temp->next->next;
    return head;
}

int main() {

    // We are storing addresses of nodes
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    Node* head = a;

    // Linking the list
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    display(head);

    head = deleteValue(a,c->val);

    display(head);

}