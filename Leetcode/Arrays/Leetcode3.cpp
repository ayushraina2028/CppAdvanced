#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int longestSubstring(string str) {
    int maxcount = 0;
    
    int n = str.length();

    if(n == 1 || n == 0) return 1;

    int i = 0;
    int j = 1;
    int count = 1;
    unordered_set<char> set;
    set.insert(str[i]);

    while(j < n) {

        if(set.find(str[j]) == set.end()) {
            count++;
            set.insert(str[j]);
            j++;
        }
        else {
            maxcount = max(count, maxcount);
            set.erase(str[i]);
            count--;
            i++;

            if(i==j) {
                count = 1;
                set.insert(str[i]);
                j++;
            } 
        }

        
    }   

    maxcount = max(count, maxcount);
    return maxcount;
}

int main() {
    string str = "abcabcbb";
    int ans = longestSubstring(str);

    cout << ans << endl;
}