#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0;
        int i = 0;
        int j = people.size()-1;

        while(i <= j) {
            if(people[j] == limit) {
                boats++;
                j--;
            }
            
            else if(people[j] < limit){
                if(people[i] + people[j] <= limit) {
                    boats++;
                    i++;
                    j--;
                }
                else {
                    boats++;
                    j--;
                } 
            }
        }

        return boats;
    }
};

int main() {
    return 0;
}