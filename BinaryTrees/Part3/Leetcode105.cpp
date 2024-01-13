#include <bits/stdc++.h>
#define null -688979
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


int main() {
    vector<int> preOrder = {3,9,20,15,7};
    vector<int> inOrder = {9,3,15,20,7};
    
}   