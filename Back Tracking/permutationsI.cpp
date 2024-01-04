#include <iostream>
#include <string>

using namespace std;

void permutations(string input, string output) {

    if(input.length()==0) {
        cout << output << " ";
        return;
    }

    for(int i = 0;i < input.size(); i++) {
        char ch = input[i];
        permutations(input.substr(0,i)+input.substr(i+1), output + ch);
    }
}

int main() {

    string str = "abc";
    cout << "Permutations of given string is -> ";
    permutations(str,"");
    cout << endl;

    return 0;
}