#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

class maxHeap {
private:
    vector<int> heap;
    int children;

    // upheapify
    void upheapify(int child_index) {
        while(child_index > 0) {

            // calculate parent index
            int parent_index = (child_index-1)/2;

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

            int left_child_index = 2*parent_index+1;
            int right_child_index = 2*parent_index+2;

            if(left_child_index >= n or right_child_index >= n) return;

            if(this->heap[parent_index] < this->heap[left_child_index] and this->heap[left_child_index] > this->heap[right_child_index]) {
                swap(this->heap[parent_index], this->heap[left_child_index]);
                parent_index = left_child_index;
            }

            else if(this->heap[parent_index] < this->heap[right_child_index] and this->heap[right_child_index] > this->heap[left_child_index]) {
                swap(this->heap[parent_index], this->heap[right_child_index]);
                parent_index = right_child_index;
            }

            else if(this->heap[parent_index] > this->heap[left_child_index] and this->heap[parent_index] > this->heap[right_child_index]) {
                break;
            }

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
        downheapify(0);
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
        this->children = x;
    }
};

int main() {
    
    int x = 1;
    // create instance of our class

    maxHeap heap(x);

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
    heap.pop();
    heap.display();
    heap.pop();
    heap.display();
}

/*
Output when x = 1;
[ 50 44 14 30 9 -1 4 3 11 ]
[ 44 30 14 11 9 -1 4 3 ]
[ 30 11 14 3 9 -1 4 ]
*/