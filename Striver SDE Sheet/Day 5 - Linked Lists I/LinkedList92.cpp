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

ListNode* reverseBetween(ListNode* head, int left, int right) {

    stack<int> st;
    ListNode* temp = head;
    int count = 1;
    while(temp != NULL) {
        if(count >= left and count <= right) {
            st.push(temp->val);
        }
        temp = temp->next;
        count++;
    }

    temp = head;
    count = 1;
    while(temp != NULL) {
        if(count >= left and count <= right) {
            temp->val = st.top();
            st.pop();
        }
        temp = temp->next;
        count++;
    }

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

    temp = head;
    cout << "Reversed Linked List -> ";
    ListNode* reverse = reverseBetween(temp,2,4);
    while(reverse != NULL) {
        cout << reverse->val << " ";
        reverse = reverse->next;
    }
    cout << endl;
}