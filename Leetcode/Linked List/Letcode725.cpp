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

vector< ListNode* > splitListToParts(ListNode* head, int k) {
    vector< ListNode* > answer;
    
    if(head == NULL) {
        for(int i = 0;i < k; i++) {
            answer.push_back(NULL);
        }
        return answer;
    }

    // first find length efficiently by fast pointer method
    ListNode* fast_pointer = head;
    int length = 1;
    
    while(fast_pointer->next != NULL and fast_pointer->next->next != NULL) {
        length += 2;
        fast_pointer = fast_pointer->next->next;
    }
    if(fast_pointer->next != NULL and fast_pointer->next->next == NULL) length++;
    cout << "Length is: " << length << endl;

    // breaking
    int size = length/k;
    int count = length % k;
    cout << "Size and Counts are -> " << size << " " << count << endl;

    ListNode* temp = head;
    while(temp != NULL) {

        ListNode* c = new ListNode(100);
        ListNode* curr_c = c;

        for(int i = 0;i < size; i++) {
            curr_c->next = temp;
            temp = temp->next;
            curr_c = curr_c->next;

            if(temp == NULL) break;
        }
        if(count and temp != NULL) {
            curr_c->next = temp;
            temp = temp->next;
            curr_c = curr_c->next;
            count--;
        }

        if(temp) {
            cout << curr_c->val << " " << temp->val << endl;
        }
        else cout << curr_c->val << endl;

        cout << "List Head: " << c->next->val << endl;

        curr_c->next = NULL;
        answer.push_back(c->next);

    }
    if(size == 0 and count == length) {
        for(int i = 0;i < k-length; i++) answer.push_back(NULL);
    }
    return answer;
}

int main() {
    vector<int> nums1 = {1,2,3};
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
    
    vector< ListNode* > answer = splitListToParts(head1,5);
    for(auto node : answer) {

        if(node == NULL) cout << "NULL ";
        ListNode* temp = node;
        while(temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}