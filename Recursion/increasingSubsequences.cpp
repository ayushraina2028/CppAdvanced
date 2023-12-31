#include <iostream>
#include <vector>

using namespace std;

void increasingSubSequence(int n, int k, vector<vector<int>>& Subsequences, int i, vector<int> vect, vector<int> nums) {
    if(i == nums.size()) {
        Subsequences.push_back(vect);
        return;
    }

    vect.push_back(nums[i]);
    increasingSubSequence(n,k,Subsequences,i+1,vect,nums);
    vect.pop_back();
    increasingSubSequence(n,k,Subsequences,i+1,vect,nums);

}

int main() {
    int n = 4;
    int size = 2;

    vector<vector<int>> Sequences;
    vector<int> v;
    vector<int> nums; // modify as required

    for(int i = 0;i < n; i++) {
        nums.push_back(i+1);
    }

    // find all subsets and filter out the ones which are of required length.
    increasingSubSequence(n,size,Sequences,0,v,nums);

    for(auto row : Sequences) {

        if(row.size() == size) {
            for(auto ele : row) {
                cout << ele << " ";
            }
            cout << "  ";
        }
        
    }
    cout << endl;
}