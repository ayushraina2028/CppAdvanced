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

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector <vector <int> > matrix(m, vector<int>(n,-1));
    vector <int> parts;

    int min_row = 0;
    int min_column = 0;
    int max_row = m - 1;
    int max_column = n - 1;
    ListNode* temp = head;

    while(min_row <= max_row && min_column <= max_column) {

        for(int i = min_column; i <= max_column;i++) {
            if(temp == NULL) return matrix;
            (matrix[min_row][i] = temp->val);
            temp = temp->next;
        }
        min_row++;

        if(min_row > max_row || min_column > max_column) {
            break;
        }

        for(int i = min_row;i <= max_row;i++) {
            if(temp == NULL) return matrix;
            (matrix[i][max_column] = temp->val);
            temp = temp->next;
        }
        max_column--;

        if(min_row > max_row || min_column > max_column) {
            break;
        }

        for(int i = max_column;i >= min_column;i--) {
            if(temp == NULL) return matrix;
            (matrix[max_row][i] = temp->val);
            temp = temp->next;
        }
        max_row--;

        if(min_row > max_row || min_column > max_column) {
            break;
        }

        for(int i = max_row;i >= min_row;i--) {
            if(temp == NULL) return matrix;
            (matrix[i][min_column] = temp->val);
            temp = temp->next;
        }
        min_column++;
    }
    return matrix;
}

int main() {
    vector<int> nums = {3,0,2,6,8,1,7,9,4,2,5,5,0};
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

    int m = 3;
    int n = 5;
    cout << "Required Spiral Matrix -> " << endl;
    vector<vector<int>> matrix = spiralMatrix(m,n,head);
    for(auto row : matrix) {
        for(auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}