#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
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

ListNode* addTwoNumber(ListNode* headA, ListNode* headB) {
    
    ListNode* tempA = headA;
    queue<int> queue1;
    ListNode* tempB = headB;
    queue<int> queue2;

    // base cases
    if(tempA == NULL) return tempB;
    else if(tempB == NULL) return tempA;


    while(tempA != NULL) {
        queue1.push(tempA->val);
        tempA = tempA->next;
    }

    while(tempB != NULL) {
        queue2.push(tempB->val);
        tempB = tempB->next;
    }

    int digit = queue1.front() + queue2.front();
    int carry = 0;
    ListNode* answer;
    queue1.pop();
    queue2.pop();
    if(digit / 10 == 0) {
        answer = new ListNode(digit);
    }
    else {
        answer = new ListNode(digit % 10);
        carry = 1;
    }

    ListNode* curr_ans = answer;

    while(queue1.size() != 0 and queue2.size() != 0) {
        digit = queue1.front() + queue2.front();
        if(carry == 1) digit++;

        if(digit / 10 == 0) {
            ListNode* node = new ListNode(digit);
            curr_ans->next = node;
            curr_ans = curr_ans->next;
            carry = 0;
        }
        else {
            ListNode* node = new ListNode(digit % 10);
            curr_ans->next = node;
            curr_ans = curr_ans->next;
            carry = 1;
        }

        queue1.pop();
        queue2.pop();
    }

    if(queue1.size() == 0 and queue2.size() != 0) {
        while(queue2.size() != 0) {
            digit = queue2.front();
            if(carry == 1) digit++;

            if(digit / 10 == 0) {
                ListNode* node = new ListNode(digit);
                curr_ans->next = node;
                curr_ans = curr_ans->next;
                carry = 0;
            }
            else {
                ListNode* node = new ListNode(digit % 10);
                curr_ans->next = node;
                curr_ans = curr_ans->next;
                carry = 1;
            }

            queue2.pop();
        }
    }

    if(queue2.size() == 0 and queue1.size() != 0) {
        while(queue1.size() != 0) {
            digit = queue1.front();
            if(carry == 1) digit++;

            if(digit / 10 == 0) {
                ListNode* node = new ListNode(digit);
                curr_ans->next = node;
                curr_ans = curr_ans->next;
                carry = 0;
            }
            else {
                ListNode* node = new ListNode(digit % 10);
                curr_ans->next = node;
                curr_ans = curr_ans->next;
                carry = 1;
            }

            queue1.pop();
        }
    }

    if(carry == 1) {
        ListNode* node = new ListNode(1);
        curr_ans->next = node;
        curr_ans = curr_ans->next;
    }

    return answer;
}

int main() {
    vector<int> nums1 = {9};
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

    vector<int> nums2 = {1,9,9,9,9,9,9,9,9,9};
    LinkedList ll2(nums2);
    ListNode* head2 = ll2.getHead();

    // printing;
    cout << "Original Linked List 2-> ";
    ListNode* temp2 = head2;
    while(temp2 != NULL) {
        cout << temp2->val << " ";
        temp2 = temp2->next;
    }
    cout << endl;

    ListNode* ans = addTwoNumber(head1,head2);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}