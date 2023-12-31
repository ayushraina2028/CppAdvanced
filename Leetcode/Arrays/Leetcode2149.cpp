#include <iostream>
#include <vector>

using namespace std;

vector<int> rearrangeOptimal(vector<int> nums) {
    int posIdx = 0;
    int negIdx = 1;

    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    vector<int> ans;

    for(int k = 0; k < n; k++) {
        if(nums[k] > 0) {
            pos.push_back(nums[k]);
        }
        else {
            neg.push_back(nums[k]);
        }
    }

    int s = pos.size();
    int i = 0, j = 0;
    while(i < s || j < s) {
        ans.push_back(pos[i]);
        ans.push_back(neg[j]);
        i++;
        j++;
    }

    return ans;
}


vector<int> rearrange(vector<int> nums) {

    int i = 0;
    int j = 0;
    bool check = true;
    int n = nums.size();

    while(i < n and j < n) {
        
        if(nums[i] > 0 and check == true) {
            i++;
            j++;
            check = false;
        }

        else if(nums[i] < 0 and check == false) {
            i++;
            j++;
            check = true;
        }

        else if(nums[i] > 0 and check == false) {

            
            if(nums[j] < 0) {
                while(j > i) {
                    swap(nums[j], nums[j-1]);
                    j--;
                }
                i++;
                j = i;
                check = true;
            }
            else j++;

        }

        else if(nums[i] < 0 and check == true) {
            
            if(nums[j] > 0) {
                while(j > i) {
                    swap(nums[j], nums[j-1]);
                    j--;
                }
                i++;
                j = i;
                check = false;
            }
            else j++;

        }
    }

    return nums;
}

int main() {
    vector<int> nums = {28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31};
    
    vector<int> nums1 = rearrange(nums);
    for(auto ele : nums1) {
        cout << ele << " ";
    }   
    cout << endl;

    vector<int> nums2 = rearrangeOptimal(nums);
    for(auto ele : nums2) {
        cout << ele << " ";
    }
    cout << endl;
}