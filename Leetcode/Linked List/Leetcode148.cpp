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

ListNode* mergeTwoLists(ListNode* headA, ListNode* headB) {
    // Updating Pointers Only in Original Linked Lists.
    ListNode* tempA = headA;
    ListNode* tempB = headB;

    if(tempA == NULL) return tempB;
    else if(tempB == NULL) return tempA;

    ListNode* answer;
    if(tempA->val <= tempB->val) {
        answer = tempA;
        tempA = tempA->next;
    }
    else if(tempA->val > tempB->val) {
        answer = tempB;
        tempB = tempB->next;
    }

    ListNode* curr_ans = answer;
    while(tempA != NULL and tempB != NULL) {
        if(tempA->val <= tempB->val) {
            curr_ans->next = tempA;
            tempA = tempA->next;
        }
        else {
            curr_ans->next = tempB;
            tempB = tempB->next;
        }

        curr_ans = curr_ans->next;
    }

    if(tempA == NULL and tempB != NULL) {
        curr_ans->next = tempB;
    }

    else if(tempB == NULL and tempA != NULL) {
        curr_ans->next = tempA;
    }

    return answer;
}


ListNode* sortList(ListNode* head) {
    if(head == NULL or head->next == NULL) return head;

    // we need to find middle left middle to break
    ListNode* slow_pointer = head;
    ListNode* fast_pointer = head;

    while(fast_pointer->next != NULL and fast_pointer->next->next != NULL) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
    }

    ListNode* a = head;
    ListNode* b = slow_pointer->next;
    slow_pointer->next = NULL;

    a = sortList(a);
    b = sortList(b);

    ListNode* sortedList = mergeTwoLists(a,b);
    return sortedList;
}

int main() {
    vector<int> nums1 = {-1,5,3,4,0};
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

    cout << "Linked List after sorting -> ";
    ListNode* ans = sortList(head1);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}