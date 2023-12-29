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
    // Storing IN a new Linked List
    ListNode* tempA = headA;
    ListNode* tempB = headB;

    if(tempA == NULL) return tempB;
    else if(tempB == NULL) return tempA;

    ListNode* answer = new ListNode(0);
    ListNode* answerhead = answer;
    while(tempA != NULL and tempB != NULL) {

        if(tempA->val <= tempB->val) {
            ListNode* node = new ListNode(tempA->val);
            tempA = tempA->next;
            answer->next = node;
            answer = answer->next;
        }
        else {
            ListNode* node = new ListNode(tempB->val);
            tempB = tempB->next;
            answer->next = node;
            answer = answer->next;
        }

    }

    if(tempA == NULL and tempB != NULL) {
        while(tempB != NULL) {
            ListNode* node = new ListNode(tempB->val);
            answer->next = node;
            answer = answer->next;
            tempB = tempB->next;
        }
    }

    else if(tempB == NULL and tempA != NULL) {
        while(tempA != NULL) {
            ListNode* node = new ListNode(tempA->val);
            answer->next = node;
            answer = answer->next;
            tempA = tempA->next;
        }
    }

    return answerhead->next;
}

ListNode* mergeTwoListsII(ListNode* headA, ListNode* headB) {
    // Updating Pointers Only in Original Linked Lists.
    ListNode* tempA = headA;
    ListNode* tempB = headB;

    if(tempA == NULL) return tempB;
    else if(tempB == NULL) return tempA;

    // fix first node, or you can create a dummy node and at last return dummy->next;
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
        // while(tempB != NULL) {
        //     curr_ans->next = tempB;
        //     tempB = tempB->next;
        //     curr_ans = curr_ans->next;
        // }
    }

    else if(tempB == NULL and tempA != NULL) {

        curr_ans->next = tempA;
        // below thing we do not require because that is already sorted;
        // while(tempA != NULL) {
        //     curr_ans->next = tempA;
        //     tempA = tempA->next;
        //     curr_ans = curr_ans->next;
        // }
    }

    return answer;
}

int main() {
    vector<int> nums1 = {1,2,4};
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

    vector<int> nums2 = {1,3,4};
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

    ListNode* ans = mergeTwoListsII(head1,head2);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}