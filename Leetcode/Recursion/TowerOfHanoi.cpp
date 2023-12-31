#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination) {

    if(n==1) {
        cout << source << " -> " << destination << endl;
        return;
    }

    // n-1 disks to helper rod
    towerOfHanoi(n-1,source, destination, helper);

    // biggest disk from A->C
    cout << source << " -> " << destination << endl;

    // n-1 disks from helper to destination rod
    towerOfHanoi(n-1,helper,source,destination);
}

int main() {
    int n = 4;
    towerOfHanoi(n,'A', 'B', 'C');
}