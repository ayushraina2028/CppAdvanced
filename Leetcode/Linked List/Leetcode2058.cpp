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

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    
    // 1 or 2 sized array cannot have critical Point
    if(head -> next == NULL or head -> next -> next == NULL) return {-1,-1};

    int idx = 1;
    ListNode* lo = head;
    ListNode* mid = head->next;
    ListNode* hi = head->next->next;

    int first_idx = -1;
    int second_idx = -1;
    int curr_first = -1;
    int min_dist = INT_MAX;
    while(hi) {
        if(mid->val > lo->val and mid->val > hi->val || mid->val < lo->val and mid->val < hi->val) { // local maxima
            if(first_idx == -1) {
                first_idx = idx;
                curr_first = first_idx;
            }
            else {
                second_idx = idx;
                int x = second_idx-curr_first;
                min_dist = min(x,min_dist);
                curr_first = second_idx;
            }
        }
        
        lo = lo -> next;
        mid = mid -> next;
        hi = hi -> next;
        idx++;
    }

    // if only 1 critical point is there return -1
    if(second_idx == -1) return {-1,-1};
    int max_dist = second_idx-first_idx;
    

    return {min_dist,max_dist};
}

int main() {
    vector<int> nums1 = {1,3,2,2,3,2,2,2,7};
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
    
    cout << "Minimum and Maximum Distance are -> ";
    vector<int> ans = nodesBetweenCriticalPoints(head1);
    for(auto ele : ans) cout << ele << " ";
    cout << endl;
}