#include <iostream>
#include <vector>
#include <climits>
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



ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = new ListNode(100);
    ListNode* even = new ListNode(100);

    ListNode* curr_odd = odd;
    ListNode* curr_even = even;

    ListNode* temp = head;

    bool flag = true; // odd
    while(temp != NULL) {
        if(flag) {
            curr_odd->next = temp;
            temp = temp->next;
            curr_odd = curr_odd->next;
            flag = false;
        }
        else {
            curr_even->next = temp;
            temp = temp->next;
            curr_even = curr_even->next;
            flag = true;
        }
    }

    curr_odd->next = even->next;
    curr_even->next = NULL;

    return odd->next;
}

int main() {
    vector<int> nums1 = {2,1,3,5,6,4,7};
    LinkedList ll1(nums1);
    ListNode* head1 = ll1.getHead();

    // printing;
    cout << "Original Linked List 1-> ";
    ListNode* temp1 = head1;
    while(temp1 != NULL) {
        cout << temp1->val << " ";
        temp1 = temp1->next;
    }
    cout << endl;

    cout << "Linked List after re ordering -> ";
    ListNode* ans = oddEvenList(head1);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}