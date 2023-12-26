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

ListNode* removeElements(ListNode* head, int value) {
    if(head == NULL) return NULL;

    ListNode* current= head;
    if(current->val == value and current->next == NULL) return NULL;
    else if(current->val == value and current->next != NULL) {
        int n = current->val;
        while(current != NULL and current->val == n) {
            current = current->next;
        }
        head = current;
    }

    if(current == NULL) return NULL;
    while(current->next != NULL) {
        if(current->next->val == value) {
            current->next = current->next->next;
        }
        else {
            current = current->next;
        }
    }

    if(current->val == value) return NULL;
    return head;
}

int main() {
    vector<int> nums = {1,1,2,2,2,2};
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
    cout << "Linked List after removing val -> ";
    int val = 1;
    ListNode* answer = removeElements(temp,val);
    while(answer != NULL) {
        cout << answer->val << " ";
        answer = answer->next;
    }

    cout << endl;
}