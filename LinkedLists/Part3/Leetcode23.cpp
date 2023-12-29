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

ListNode* merge(ListNode* headA, ListNode* headB) {
    if(headA == NULL) return headB;
    else if(headB == NULL) return headA;

    // dummmy node
    ListNode* answer = new ListNode(100);

    ListNode* tempA = headA;
    ListNode* tempB = headB;

    ListNode* curr_ans = answer;
    while(tempA != NULL and tempB != NULL) {
        if(tempA->val <= tempB->val) {
            curr_ans->next = tempA;
            tempA = tempA->next;
            curr_ans = curr_ans->next;
        }
        else {
            curr_ans->next = tempB;
            tempB = tempB->next;
            curr_ans = curr_ans->next;
        }
    }

    if(tempA == NULL and tempB != NULL) {
        curr_ans->next = tempB;
    }
    else curr_ans->next = tempA;

    return answer->next;
}

ListNode* mergeKLists(vector< ListNode* > heads) {
    int n = heads.size();
    if(n == 1) return heads[0];

    else if(n == 2) return merge(heads[0], heads[1]);

    while(heads.size() != 1) {
        ListNode* mergedHead;
        ListNode* a = heads[0];
        heads.erase(heads.begin());
        ListNode* b = heads[0];
        heads.erase(heads.begin());

        mergedHead = merge(a,b);
        heads.push_back(mergedHead);
    }
    return heads[0];
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

    vector<int> nums3 = {2,6};
    LinkedList ll3(nums3);
    ListNode* head3 = ll3.getHead();

    // printing;
    cout << "Original Linked List 2-> ";
    ListNode* temp3 = head3;
    while(temp3 != NULL) {
        cout << temp3->val << " ";
        temp3 = temp3->next;
    }
    cout << endl;

    cout << "Linked Lists after merging -> " << endl;
    vector< ListNode* > heads = {head1, head2, head3};
    ListNode* ans = mergeKLists(heads);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}