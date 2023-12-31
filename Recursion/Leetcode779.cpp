#include <iostream>
using namespace std;

int kthGrammar(int n, int k) {
    if(n==1) return 0;

    if(k % 2 == 0) {
        return abs(1-kthGrammar(n-1,k/2));
    }
    return kthGrammar(n-1,(k/2)+1);
}

int main() {
    int n = 4;
    int k = 4;

    cout << kthGrammar(n,k) << endl;
}