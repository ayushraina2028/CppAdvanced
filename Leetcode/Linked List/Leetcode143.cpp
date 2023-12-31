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

ListNode* reOrderList(ListNode* head) {
    if(head == NULL || head->next == NULL or head->next->next == NULL) return head;

    ListNode* slow_pointer = head;
    ListNode* fast_pointer = head;

    while(fast_pointer->next != NULL and fast_pointer->next->next != NULL) {
        fast_pointer = fast_pointer->next->next;
        slow_pointer = slow_pointer->next;
    }

    ListNode* newHead = reverseListRecursive(slow_pointer);
    slow_pointer->next = NULL;

    ListNode* answer = new ListNode(0);
    ListNode* curr_head = head;
    ListNode* curr_newHead = newHead;
    ListNode* curr_answer = answer;

    cout << curr_head -> val << " " << curr_newHead -> val << endl;
    bool flag = true;
    while(curr_head != NULL and curr_newHead != NULL) {
        if(flag) {
            curr_answer->next = curr_head;
            curr_head = curr_head->next;
            curr_answer = curr_answer->next;
            flag = false;        
        }
        else{
            curr_answer->next = curr_newHead;
            curr_newHead = curr_newHead->next;
            curr_answer = curr_answer->next;
            flag = true;
        }
    }

    if(curr_head == NULL and curr_newHead != NULL) {
        curr_answer->next = curr_newHead;
        curr_answer->next->next = NULL;
    }
    else if(curr_head != NULL and curr_newHead == NULL) {
        curr_answer->next = curr_head;
        curr_answer->next->next = NULL;
    }
    return answer->next;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6};
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
    cout << "ReOrdered Linked List -> ";
    
    ListNode* reverse = reOrderList(temp);
    while(reverse != NULL) {
        cout << reverse->val << " ";
        reverse = reverse->next;
    }
    cout << endl;
}