#include <iostream>
#include <vector>

using namespace std;

int maxSatisfaction(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int normalsum = 0;
    for(int i = 0; i<customers.size(); i++) {
        if(grumpy[i] == 0) normalsum += customers[i];
    }

    cout << "initial normal sum -> " << normalsum << endl;

    // make window over grumpy array and save successive iterations.
    vector<int> nums;
    for(int i = 0;i < minutes; i++) {
        if(grumpy[i] == 1) normalsum += customers[i];
    }
    nums.push_back(normalsum);
    cout << " next normal sum -> " << normalsum << endl;

    // run the above window further
    for(int j = minutes; j < grumpy.size(); j++) {
        

        if(grumpy[j] == 1) normalsum += customers[j];
        if(grumpy[j-minutes] == 1) normalsum -= customers[j-minutes];

        nums.push_back(normalsum);

    }

    int maxi = 0;
    for(auto ele : nums) {
        maxi = max(maxi, ele); 
    }
    
    return maxi;
}

int main() {
    vector<int> customers = {4,10,10};
    vector<int> grumpy =    {1,1,0};
    int minutes = 2;   

    int maximumSatisfy = maxSatisfaction(customers, grumpy, minutes);
    cout << maximumSatisfy << endl;
}