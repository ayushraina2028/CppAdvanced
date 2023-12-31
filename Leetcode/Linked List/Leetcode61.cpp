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

ListNode* rotateRight(ListNode* head, int k) {
    int count = 0;
    ListNode* temp = head;

    if(head == NULL) return NULL;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    int idx = k % count;
    temp = head;

    if(idx == 0) return head;
    int i = 0;
    while(i < count-idx-1) {
        temp = temp->next;
        i++;
    }

    ListNode* temp2 = temp->next;
    ListNode* curr_temp2 = temp2;
    temp->next = NULL;

    while(curr_temp2 != NULL and curr_temp2->next != NULL) {
        curr_temp2 = curr_temp2->next;
    }

    if(curr_temp2 != NULL) curr_temp2->next = head;
    head = temp2;

    return head;
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

    cout << "Linked List after k rotations -> ";
    int k = 5;
    ListNode* ans = rotateRight(head,k);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    // another method we can use, use other pointer and keep it moving till you get different value
    // then update, in our method we are removing one at time,in tis method all will be removed at once.
}