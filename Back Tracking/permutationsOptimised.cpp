#include <iostream>
#include <string>

using namespace std;

void permutations(string &input, int i) {

    if(i == input.size()-1) {
        cout << input << " ";
        return;
    }
    
    for(int index = i;index < input.size(); index++) {
        // swap to first;
        swap(input[index], input[i]);

        // make next call;
        permutations(input,i+1);

        // revert the swap while backtracking
        swap(input[index],input[i]);
    }
}

int main() {

    string str = "abc";
    cout << "Permutations of given string is -> ";
    permutations(str,0);
    cout << endl;

    return 0;
}