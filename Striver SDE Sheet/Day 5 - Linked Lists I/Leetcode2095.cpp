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

ListNode* deleteMiddle(ListNode* head) {
    ListNode* curr = head;
    // Length 1
    if(curr->next == NULL) return NULL;

    // Length 2
    else if(curr->next->next == NULL) {
        curr->next = NULL;
        return curr;
    }

    // Otherwise;
    int length = 1;
    ListNode* fast_pointer = head;
    ListNode* slow_pointer = head;
    ListNode* temp = new ListNode(0);
    temp->next = head;
    slow_pointer = temp;

    while(fast_pointer->next != NULL and fast_pointer->next->next != NULL) {
        fast_pointer = fast_pointer->next->next;
        slow_pointer = slow_pointer->next;

        length += 2;
    }

    if(fast_pointer->next != NULL and fast_pointer->next->next == NULL) {
        length++;
    }

    if(length % 2 == 0) {
        slow_pointer = slow_pointer->next;
        slow_pointer->next = slow_pointer->next->next;
    }
    else {
        slow_pointer->next = slow_pointer->next->next;
    }

    return head;
}   

int main() {
    vector<int> nums = {2,1};
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
    cout << "Linked List after removing middle element -> ";
    ListNode* answer = deleteMiddle(temp);
    while(answer != NULL) {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;
}