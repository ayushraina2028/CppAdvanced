#include <iostream>
#include <queue>
using namespace std;

int main() {

    // declaration
    // default is maxHeap
    priority_queue <int> hp;
    
    // push elements
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);

    cout << hp.top() << endl;

    // making priority queue, min heap
    priority_queue <int, vector<int>, greater<int> > minHeap;

    // similarly max heap can be declared in this way
    priority_queue <int, vector<int>, less<int> > maxHeap;

    // implementing priority queue from a vector
    vector <int> v = {9, 6, 1, 19, 3, 2, 8, 12, 5};
    priority_queue <int, vector<int>, less<int> > maxHeap2(v.begin(), v.end());
    cout << maxHeap2.top() << endl;

    priority_queue <int, vector<int>, greater<int> > minHeap2(v.begin(), v.end());
    cout << minHeap2.top() << endl;
    // above we passed iterator for range to be converted into heap.

    


}