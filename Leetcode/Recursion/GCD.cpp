#include <iostream>
using namespace std;

int hcf(int a, int b) {
    if(b % a == 0) return a;
    return hcf(b % a, a);
}

int main() {
    int a = 140;
    int b = 49;

    cout << hcf(a,b);
}