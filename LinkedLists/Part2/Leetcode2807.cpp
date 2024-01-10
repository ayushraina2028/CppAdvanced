#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int n) {
        this->val = n;
        this->next = NULL;
    }
};
class LinkedList {
public:
    ListNode* head;
    LinkedList(vector<int> nums) {
        head = new ListNode(nums[0]);
        ListNode* temp = head;
        for(int i = 1;i < nums.size(); i++) {
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
        }
    }

    ListNode* getHead() {
        return this->head;
    }
};

int gcd(int a,int b) {
    if(b % a == 0) return a;
    else return gcd(b % a, a);
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    if(head == NULL or head->next == NULL) return NULL;

    ListNode* temp = head;
    while(temp->next != NULL) {

        ListNode* node = new ListNode(gcd(temp->val, temp->next->val));
        node->next = temp->next;
        temp->next = node;
        temp = node->next;
    }

    return head;
}

int main() {
    vector<int> nums = {18,6,10,3};
    LinkedList ll(nums);
    ListNode* head = ll.getHead();

    // printing;
    cout << "Linked List Before -> ";
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = head;
    cout << "Linked List after modifying -> ";
    ListNode* newHead = insertGreatestCommonDivisors(temp);
    while(newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
}   