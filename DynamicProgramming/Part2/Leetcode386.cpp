#include <iostream>
#include <vector>
using namespace std;

void f(int i, int n) {

    if(i > n) return;
    else if(i <= n and i != 0) {
        cout << i << " ";
    }

    // below is recurrence relation.
    if(i != 0) {
        for(int j = 0;j <= 9; j++) {
            f(10*i + j, n);
        }
    }
    else {
        for(int j = 1;j <= 9; j++) {
            f(10*i + j, n);
        }
    }
    
}

int main() {
    int n = 23;
    f(0,n);
    return 0;
}