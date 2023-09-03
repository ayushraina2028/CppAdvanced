#include <iostream>
using namespace std;

class Node{
public: 
    int val;
    Node* next;

    Node(int n) {
        this->val = n;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void insertAtEnd(int val) {
        Node* newEnd = new Node(val);
        if(size==0) {
            this->head = newEnd;
            this->tail = newEnd;
        }
        else {
            this->tail->next = newEnd;
            this->tail = newEnd;
        }
        size++;
    }

    void insertAtBeginning(int val) {
        Node* newHead = new Node(val);

        if(size == 0) {
            this->head = newHead;
            this->tail = newHead;
        }
        else {
            newHead->next = head;
            this->head = newHead;
        }
        size++;
    }

    void insertAtIdx(int index, int val) {

        if(index < 0 || index > size) {
            cout << "invalid size";
            return;
        }

        if(index == 0) insertAtBeginning(val);
        else if(index == size) insertAtEnd(val);

        else{
            Node* newNode = new Node(val);
            Node* temp = head;
            int i = 0;
            for(int i = 0;i < index-1;i++) {
                temp = temp->next;
            }
            
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
        
    }

    void deleteAtBeginning() {

        if(size <= 0) {
            cout << "Invalid" << endl;
            return;
        }

        if(size==1) {
            head=NULL;
            return;
        }

        head = head->next;
        size--;
    }

    void deleteAtEnd() {
        
        if(size <= 0) {
            cout << "Invalid" << endl;
            return;
        }

        Node* temp = head;
        while(temp->next != tail) temp = temp->next;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void deleteAtIndex(int idx) {
        if(idx < 0 || idx > size) {
            cout << "invalid index" << endl;
            return;
        }

        else if(idx == 0) deleteAtBeginning();
        else if(idx == size) deleteAtEnd();

        else {
            Node* temp = head;
            for(int i = 0;i < idx-1;i++) temp = temp->next;
            temp->next = temp->next->next;
        }
    }

    void getIdx(int idx) {
        if(idx == 0) cout << head->val << endl;
        else if(idx == size-1) cout << tail->val << endl;
        else if(idx < 0 || idx >= size) {
            cout << "invalid" << endl;
            return;
        } 
        else {
            Node* temp = head;
            for(int i = 0;i < idx;i++) {
                temp = temp->next;
            }
            cout << temp->val << endl;
        }  
    }

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.display();
    cout << ll.size << endl;
    ll.insertAtBeginning(40);
    ll.display();
    ll.insertAtIdx(2,50);
    ll.display();
    ll.insertAtBeginning(70);
    ll.insertAtBeginning(90);
    ll.insertAtEnd(80);
    ll.getIdx(3);
    cout << ll.size << endl;
    ll.display();
    ll.deleteAtBeginning();
    ll.display();
    ll.deleteAtEnd();
    ll.display();
    ll.deleteAtIndex(3);
    ll.display();

}