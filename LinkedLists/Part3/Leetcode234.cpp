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

bool isPalindrome(ListNode* head) {
    ListNode* newHead = new ListNode(100);
    ListNode* curr_head = head;
    ListNode* curr_newHead = newHead;

    while(curr_head != NULL) {
        ListNode* node = new ListNode(curr_head->val);
        curr_newHead->next = node;
        curr_head = curr_head->next;
        curr_newHead = curr_newHead->next;
    }

    newHead = reverseListRecursive(newHead->next);
    ListNode* a = head;
    ListNode* b = newHead;

    while(a != NULL and b != NULL) {
        if(a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }

    return true;
}

bool isPalindromeII(ListNode* head) {
    // Ultra Pro Max Method, First ans Second Halves of Linked List are reverse of Each other in case of Palindrome List.
    if(head == NULL or head->next == NULL) return head;

    // we need to find middle left middle to break
    ListNode* slow_pointer = head;
    ListNode* fast_pointer = head;

    while(fast_pointer->next != NULL and fast_pointer->next->next != NULL) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
    }

    ListNode* newHead = reverseListRecursive(slow_pointer->next);
    ListNode* a = head;
    ListNode* b = newHead;

    while(b) {
        if(a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }
    return true;
}

int main() {
    vector<int> nums = {1,2,2,1};
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
    cout << "Palindrome Linked List -> ";
    cout << isPalindrome(temp) << endl;
}