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

ListNode* reverseListRecursive(ListNode* head) {
    if(head == NULL or head -> next == NULL) return head;

    ListNode* newHead = reverseListRecursive(head->next);
    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
}
ListNode* reverseBetween(ListNode* head, int left, int right) {
    // break the list into 3 lists and reverse the middle list
    ListNode* temp = head;
    int count = 1;

    while(temp != NULL and count != left-1 and left != 1) {
        temp = temp->next;
        count++;
    }
    ListNode* left_list = temp;

    while(temp != NULL and count != right) {
        temp = temp->next;
        count++;
    }

    ListNode* right_list = temp;
    //cout << left_list -> val << " " << right_list -> val << endl;

    ListNode* temp1 = right_list;
    right_list = right_list->next;
    temp1->next = NULL;

    ListNode* newHead;
    if(left == 1) {
        newHead = reverseListRecursive(left_list);
        ListNode* curr_newHead = newHead;
        while(curr_newHead->next != NULL) {
            curr_newHead = curr_newHead -> next;
        }

        curr_newHead->next = right_list;
        return newHead;
    }
    else {
        newHead = reverseListRecursive(left_list->next);
        left_list->next = newHead;

        temp1 = newHead;
        while(temp1->next != NULL) {
            temp1 = temp1->next;
        }

        temp1->next = right_list;
    }
    
    return head;
}

ListNode* reverseEvenLengthGroups(ListNode* head) {
    ListNode* temp = head;
    int gap = 1;

    while(temp != NULL and temp->next != NULL) {
        int remLen = 0;
        ListNode* curr_temp = temp->next;

        for(int i = 0;i < gap and curr_temp != NULL; i++) {
            curr_temp = curr_temp->next;
            remLen++;
        }

        if(remLen < gap+1) gap = remLen-1;

        if(gap % 2 != 0) reverseBetween(temp,2,2+gap);
        gap++;

        for(int i = 0; temp != NULL and i < gap; i++) {
            temp = temp->next;
        }
    }
    
    return head;
}

int main() {
    vector<int> nums1 = {1,2,3,4,5,6,7,8,9,10};
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
    
    cout << "Modified Linked List -> ";
    ListNode* newHead = reverseEvenLengthGroups(head1);
    while(newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
}