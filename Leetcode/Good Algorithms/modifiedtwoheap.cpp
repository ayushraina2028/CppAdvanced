#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

// In this modified heap, we can give 2^x children where as in normal heap it is 2^1, we can even give 3,5 etc also.
// To try this change number of children in main function, while calling constructor
class maxHeap {
private:
    vector<int> heap;
    int children;

    // upheapify
    void upheapify(int child_index) {
        while(child_index > 0) {

            // calculate parent index
            int parent_index = (child_index-1)/children;

            // if child is bigger than parent then swap
            if(this->heap[child_index] > this->heap[parent_index]) {
                swap(this->heap[child_index], this->heap[parent_index]);
                child_index = parent_index;
            }
            // if child is already smaller then break
            else{
                break;
            }

        }
    }

    // downheapify
    void downheapify(int parent_index) {
        int n = this->heap.size();
        while(parent_index < n) {

            int max_element_idx = -1;
            int max_element = INT_MIN;
            for(int i = 1;i <= children; i++) {

                int idx = children*parent_index + i;
                if(idx >= n) return;

                if(max_element < this->heap[children*parent_index + i]) {
                    max_element = this->heap[children*parent_index + i];
                    max_element_idx = children*parent_index+i;
                }
            }

            if(this->heap[parent_index] > this->heap[max_element_idx]) return;

            swap(this->heap[parent_index], this->heap[max_element_idx]);
            parent_index = max_element_idx;

        }
    }
public:

    // delete max i.e pop()
    void pop() {
        if(empty()) {
            cout << "heap is empty" << endl;
            return;
        }
        swap(this->heap[0], this->heap[heap.size()-1]);
        heap.pop_back();
        this->downheapify(0);
    }

    // peak element
    int peak() {
        if(empty()) return INT_MAX;
        return this->heap[0];
    }

    // push method
    void push(int element) {
        this->heap.push_back(element);
        this->upheapify(this->heap.size()-1); // newly added element is at end;
    }

    // display method
    void display() {
        cout << "[ ";
        for(auto element : this->heap) {
            cout << element << " ";
        }
        cout << "]" << endl;
    }

    // Empty check
    bool empty() {
        return this->heap.size() == 0;
    }

    // constructor
    maxHeap(int x) {
        this->children = pow(2,x);
    }
};

int main() {
    
    // give x accordingly.
    int x = 2;

    // create instance of our class
    maxHeap heap(x);

    // add your elements here.
    heap.push(3);
    heap.push(4);
    heap.push(11);
    heap.push(9);
    heap.push(14);
    heap.push(-1);
    heap.push(30);
    heap.push(44);
    heap.push(50);

    // display function
    heap.display();

    // pop max function 
    heap.pop();
    
    heap.display();
}
