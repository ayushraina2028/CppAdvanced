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

ListNode* middleNode(ListNode* head) {
    vector< ListNode* > nums;
    ListNode* temp = head;

    while(temp != NULL) {
        nums.push_back(temp);
        temp = temp->next;
    }

    int n = nums.size();
    return nums[n/2];
}

ListNode* middleNodeII(ListNode* head) {
    
    if(head->next == NULL) return head;

    ListNode* slow_pointer = head;
    ListNode* fast_pointer = head;

    while(fast_pointer->next != NULL and fast_pointer->next->next != NULL) {
        fast_pointer = fast_pointer->next->next;
        slow_pointer = slow_pointer->next;
    }

    // case for even length;
    if(fast_pointer->next != NULL and fast_pointer->next->next == NULL) return slow_pointer->next;

    return slow_pointer;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6};
    LinkedList ll(nums);
    ListNode* head = ll.getHead();

    // printing;
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // method I (Extra Space)
    ListNode* middle1 = middleNode(head);
    cout << middle1->val << endl;

    // method II (fast and slow pointer)
    ListNode* middle2 = middleNodeII(head);
    cout << middle2->val << endl;

    // method III (2 for loops 1 for length and other for traversal)
}