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

ListNode* partition(ListNode* head, int x) {
    ListNode* answer = new ListNode(100);
    ListNode* curr_ans = answer;
    ListNode* temp = head;

    int last_val = INT_MIN;
    while(temp != NULL) {
        if(temp->val < x) {
            ListNode* node = new ListNode(temp->val);
            curr_ans->next = node;
            curr_ans = curr_ans->next;
            last_val = temp->val;
        }
        temp = temp->next;
    }

    cout << last_val << endl;
    temp = head;
    while(temp != NULL) {
        if(temp->val > last_val and temp->val >= x) {
            ListNode* node = new ListNode(temp->val);
            curr_ans->next = node;
            curr_ans = curr_ans->next;
        }

        temp = temp->next;
    }
    return answer->next;
}

ListNode* partitionII(ListNode* head, int x) {
    ListNode* lo = new ListNode(0);
    ListNode* hi = new ListNode(0);

    ListNode* curr_lo = lo;
    ListNode* curr_hi = hi;

    ListNode* temp = head;
    while(temp != NULL) {
        if(temp->val < x) {
            curr_lo -> next = temp;
            temp = temp->next;
            curr_lo = curr_lo->next;
        }
        else {
            curr_hi -> next = temp;
            temp = temp->next;
            curr_hi = curr_hi -> next;
        }
    }

    curr_lo->next = hi->next;
    curr_hi->next = NULL;

    return lo->next;
}

int main() {
    vector<int> nums1 = {1,4,3,2,5,2};
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

    cout << "Linked List after partition -> ";
    int x = 3;
    ListNode* ans = partitionII(head1,x);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}