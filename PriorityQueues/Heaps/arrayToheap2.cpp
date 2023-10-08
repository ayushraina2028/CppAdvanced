#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class maxHeap{

// private property
    vector <int> hp;

public:

    // up heapify function
    void upheapify(int child_index) {
        
        while(child_index > 0) {
            int parent_index = (child_index-1)/2;
            if(this->hp[parent_index] < this->hp[child_index]) {
                swap(this->hp[parent_index], this->hp[child_index]);
                child_index=parent_index;
            }
            else {
                break;
            }
        }
    }

    // insert element
    void push(int element) {
        this->hp.push_back(element);
        upheapify(hp.size()-1); // element is present at last index
    }

    // display function
    void display() {
        cout << "[ ";
        for(auto ele : this->hp) {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }

    // isEmpty function
    bool isEmpty() {
        return this->hp.size() == 0;
    }

    // highest priority elemet
    int peak() {
        return this->hp[0];
    }

    // downheapify
    void downheapify(int index) {
        while(index < this->hp.size()) {
            int left_child = 2*index + 1;
            int right_child = 2*index + 2;

            // comparison with left child
            if(left_child >= hp.size()) {
                return;
            }
            
            int maxIdx = index;
            if(this->hp[left_child] > this->hp[index]) {
                maxIdx = left_child;
            }

            // comparsion with right child  
            if(right_child < this->hp.size() and this->hp[right_child] > this->hp[maxIdx]) {
                maxIdx = right_child;
            }
            
            // swapping
            if(maxIdx != index) {
                swap(this->hp[maxIdx], this->hp[index]);
                index = maxIdx;
            }
            else {
                // if no swap then it means already a heap.
                break;
            }
        }
    }

    // pop function which removes highest priority element
    void pop() {
        if(isEmpty()) {
            return;
        }

        else{
            swap(this->hp[0], this->hp[hp.size()-1]);
            this->hp.pop_back();
            downheapify(0);
        }
    }

    // removing element at custom index;
    void pop_custom_element(int index) {
        this->hp[index] = INT_MAX;
        upheapify(index);
        pop();
    }   


    // We will downheapify all except leaf nodes
    // An Optimised version which is using O(n) time and previous one was O(nlogn).
    maxHeap(vector <int> v) {
        hp = v;
        int n = v.size();
        for(int i = n/2;i >= 0;i--) {
            downheapify(i);
        }
    }

};


int main() {

    vector <int> v = {9, 6, 1, 19, 3, 2, 8, 12, 5};
    maxHeap hp(v);
    hp.display();

    hp.push(100);
    hp.display();
}