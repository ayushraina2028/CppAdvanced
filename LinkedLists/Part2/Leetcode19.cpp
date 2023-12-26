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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // method I use space
    ListNode* temp = head;
    vector< ListNode* > nums;

    while(temp != NULL) {
        nums.push_back(temp);
        temp = temp->next;
    }

    int s = nums.size();
    int idx = s-n;

    if(idx < 0) return head;
    else if(s == 1 and n == 1) return NULL;
    else if(idx == 0) return nums[1];

    nums[idx-1]->next = nums[idx-1]->next->next;
    return nums[0];
}

ListNode* removeNthFromEndII(ListNode* head, int n) {
   
    // a better way of finding length;
    ListNode* fast_pointer = head;
    int count = 1;
    while(fast_pointer->next != NULL and fast_pointer->next->next != NULL) {

        count += 2;
        fast_pointer = fast_pointer->next->next;

    }

    if(fast_pointer->next != NULL and fast_pointer->next->next == NULL) {
        count++;
    }

    int idx = count-n;

    if(count == 1 and n == 1) return NULL;
    else if(idx < 0) return head;
    else if(idx == 0) return head->next;


    ListNode* slow_pointer = head;
    int i = 0;
    while(i < idx-1) {
        slow_pointer = slow_pointer->next;
        i++;
    }
    slow_pointer->next = slow_pointer->next->next;
    return head;
}

ListNode* removeNthFromEndIII(ListNode* head, int n) {
    ListNode* fast_pointer = head;
    for(int i = 0;i < n; i++) {
        fast_pointer = fast_pointer->next;
    }

    // now run simultaneously;
    if(fast_pointer == NULL) return head->next;
    ListNode* slow_pointer = head;

    while(fast_pointer->next != NULL) {
        fast_pointer = fast_pointer->next;
        slow_pointer = slow_pointer->next;
    }

    slow_pointer->next = slow_pointer->next->next;
    return head;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6};
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

    // store original head in temp
    temp = head;

    // Method I (use space)
    cout << "Method I (using space) -> ";
    int n = 2;
    ListNode* ans1 = removeNthFromEnd(head,n);
    while(ans1 != NULL) {
        cout << ans1->val << " ";
        ans1 = ans1->next;
    }
    cout << endl;

    // Method II (slow and fast I)
    LinkedList ll2(nums);
    ListNode* head2 = ll2.getHead();
    cout << "Method II (using slow and fast) -> ";
    n = 2;
    ListNode* ans2 = removeNthFromEndII(head2,n);
    while(ans2 != NULL) {
        cout << ans2->val << " ";
        ans2 = ans2->next;
    }
    cout << endl;

    // Method III (slow and fast II)
    LinkedList ll3(nums);
    ListNode* head3 = ll3.getHead();
    cout << "Method III (using slow and fast, modified) -> ";
    n = 2;
    ListNode* ans3 = removeNthFromEndIII(head3,n);
    while(ans3 != NULL) {
        cout << ans3->val << " ";
        ans3 = ans3->next;
    }
    cout << endl;
}