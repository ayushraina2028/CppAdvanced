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

ListNode* deleteDuplicates(ListNode* head) {
    
    if(head == NULL) return NULL;
    else if(head->next == NULL) return head;

    ListNode* temp = head;
    // if we have repeated values at start only;
    while(temp->next != NULL and temp->val == temp->next->val) {
        temp = temp->next;
        head = temp;
    }

    // remaining repeated values;
    while(temp->next != NULL) {
        if(temp->next->val == temp->val) {
            temp->next = temp->next->next;
        }
        else temp = temp->next;
    }

    return head;
}

ListNode* deleteDuplicatesII(ListNode* head) {
    if(head==NULL) return NULL;
    else if(head->next == NULL) return head;

    ListNode* temp = head;
    ListNode* curr_temp = head->next;

    while(curr_temp) {
        while(curr_temp and temp->val == curr_temp->val) {
            curr_temp = curr_temp->next;
        }

        temp->next = curr_temp;
        temp = curr_temp;

        if(curr_temp) curr_temp->next;
    }

    return head;
}

int main() {
    vector<int> nums = {1,1,2,3,3};
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

    cout << "Linked List after removing duplicates -> ";
    ListNode* ans = deleteDuplicatesII(head);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    // another method we can use, use other pointer and keep it moving till you get different value
    // then update, in our method we are removing one at time,in tis method all will be removed at once.
}