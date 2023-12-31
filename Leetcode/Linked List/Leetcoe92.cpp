#include <iostream>
#include <vector>
#include <stack>
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

ListNode* reverseListRecursive(ListNode* head) {
    if(head == NULL or head -> next == NULL) return head;

    ListNode* newHead = reverseListRecursive(head->next);
    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    // break the list into 3 lists and reverse the middle list
    ListNode* temp = head;
    int count = 1;

    while(temp != NULL and count != left-1 and left != 1) {
        temp = temp->next;
        count++;
    }
    ListNode* left_list = temp;

    while(temp != NULL and count != right) {
        temp = temp->next;
        count++;
    }

    ListNode* right_list = temp;
    cout << left_list -> val << " " << right_list -> val << endl;

    ListNode* temp1 = right_list;
    right_list = right_list->next;
    temp1->next = NULL;

    ListNode* newHead;
    if(left == 1) {
        newHead = reverseListRecursive(left_list);
        ListNode* curr_newHead = newHead;
        while(curr_newHead->next != NULL) {
            curr_newHead = curr_newHead -> next;
        }

        curr_newHead->next = right_list;
        return newHead;
    }
    else {
        newHead = reverseListRecursive(left_list->next);
        left_list->next = newHead;

        temp1 = newHead;
        while(temp1->next != NULL) {
            temp1 = temp1->next;
        }

        temp1->next = right_list;
    }
    
    return head;
}

ListNode* reverseBetweenII(ListNode* head, int left, int right) {
    if(head == NULL or head->next == NULL or left == right) return head;

    ListNode* a = NULL;
    ListNode* b = NULL;
    ListNode* c = NULL;
    ListNode* d = NULL;
    ListNode* e = NULL;

    ListNode* temp = head;
    int count = 1;

    while(temp) {

        if(count == left-1) a = temp;
        else if(count == left) b = temp;
        else if(count == right) c = temp;
        else if(count == right+1) d = temp;

        count++;
        temp = temp -> next;
    }

    // breaking lists
    if(a != NULL) a->next = NULL;
    c->next = NULL;

    if(a != NULL) {
        ListNode* reversedHead = reverseListRecursive(b);
        b->next = d;
        a->next = reversedHead;
        return head;
    }
    c = reverseListRecursive(b);
    b->next = d;
    return c;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    LinkedList ll(nums);
    ListNode* head = ll.getHead();

    // printing;
    cout << "Original Linked List -> ";
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = head;
    cout << "Reversed Linked List -> ";
    int m = 1;
    int n = 5;
    ListNode* reverse = reverseBetweenII(temp,m,n);
    while(reverse != NULL) {
        cout << reverse->val << " ";
        reverse = reverse->next;
    }
    cout << endl;
}