#include <iostream>
#include <vector>
#include <stack>
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

ListNode* reverseList(ListNode* head) {

    stack< ListNode* > st;
    ListNode* temp = head;

    while(temp != NULL) {
        st.push(temp);
        temp = temp->next;
    }

    head->next = NULL;
    if(st.size() != 0) {
        head = st.top();
        st.top()->next == NULL;
        st.pop();
    }

    temp = head;
    while(st.size() != 0) {
        temp->next = st.top();
        st.top()->next == NULL;
        temp = temp->next;
        st.pop();
    }
    return head;
}

ListNode* reverseListRecursive(ListNode* head) {
    if(head == NULL or head -> next == NULL) return head;

    ListNode* newHead = reverseListRecursive(head->next);
    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
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

    temp = head;
    cout << "Reversed Linked List -> ";
    ListNode* reverse = reverseListRecursive(temp);
    while(reverse != NULL) {
        cout << reverse->val << " ";
        reverse = reverse->next;
    }
    cout << endl;
}