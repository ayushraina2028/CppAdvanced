#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int bestClosingTime(string customers) {

    int n = customers.length();
    int no = 0;
    int yes = 0;

    vector<int> prefixNo(n+1,0);
    for(int i = 0;i < n; i++) {
        if(customers[i] == 'N') {
            no++;
            prefixNo[i] = no;
        }
        else prefixNo[i] = no;
    }

    vector<int> suffixyes(n+1,0);
    for(int i = n-1; i >= 0; i--) {
        if(customers[i] == 'Y') {
            yes++;
            suffixyes[i] = yes;
        }
        else suffixyes[i] = yes;
    }

    for(int i = 0; i < n; i++) {
        if(customers[i] == 'N') {
            prefixNo[i]--;
        }
    }
    suffixyes[0] = yes;
    prefixNo[n] = no;
    
    int bestClose = 0;
    int penalty = INT_MAX;

    for(int i = 0; i < n+1; i++) {
        cout << prefixNo[i] << suffixyes[i] << endl;
        int penal = prefixNo[i] + suffixyes[i];
        if(penalty > penal) {
            penalty = penal;
            bestClose = i;
        }    
    }

    return bestClose;
}

int main() {
    string customers = "YN";
    int penalty = bestClosingTime(customers);
    cout << penalty << endl;
}