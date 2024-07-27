#include <bits/stdc++.h>
using namespace std;

int main() {
    int D = 2;
    int K = 4;
    int n = 3;
    vector<vector<string>> X = {{"x11","x12"}, {"x21", "x22"}, {"x31", "x32"}};
    vector<string> y = {"1", "2", "4"};
    vector<vector<string>> G(n*K, vector<string>(K*D+n, "0"));
    
    // print
    for(auto row : G) {
        for (auto x : row) {
            cout << x << " ";
        }
        cout << endl; 
    }

    // Fill 1 by 1
    int rowGap = 0;
    int colGap = 0;
    int colcolGap = 0;

    for(int i = 0; i < n; i++) {
        colcolGap = 0;
        for(int j = 0;j < K-1; j++) {

            int index = stoi(y[i])*D-D;
            cout <<"index " <<  index << " ";

            for(int k = 0;k < D; k++) {
                cout << "add " << "-" + X[i][k] << " at " << "G[" << j + rowGap << "][" << k +index << "]" << endl;
                G[j+rowGap][k+index] = "-" + X[i][k];
            }

            if(colcolGap > 0) {
                if(G[j+rowGap][colcolGap] != "0") {
                    colcolGap += D;
                }
                for(int k = 0;k < D; k++) {
                    cout << colcolGap << " ";
                    G[j+rowGap][k+colcolGap] = X[i][k];
                }
                colcolGap += D;
            }

            else if(colGap == 0) {
                if(G[j+rowGap][colcolGap] != "0") {
                    colcolGap += D;
                    for(int k = 0;k < D; k++) {
                        G[j+rowGap][k+colcolGap] = X[i][k];
                    }
                }
                else {
                    for(int k = 0;k < D; k++) {
                        G[j+rowGap][k+colcolGap] = X[i][k];
                    }
                }
                colcolGap += D;
            }

            else if(colGap > 0 and colcolGap == 0) {
                if(G[j+rowGap][colcolGap] != "0") colcolGap += D;
                for(int k = 0;k < D; k++) {
                    G[j+rowGap][k+colcolGap] = X[i][k];
                }
                colcolGap += D;

            }

            G[j+rowGap][K*D + i] = "1";
        }
        rowGap += K-1;
        colGap += D;
    }

    for (int i = 0;i < n; i++) {
        for (int j = 0;j < n; j++) {
            G[n*(K-1) + i][K*D + i] = "-1";
        }
    }

    cout << "matrix 1st fill is this => " << endl;
    for(auto row : G) {
        for (auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}