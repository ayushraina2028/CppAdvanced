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

class BinaryTree {
public:
    TreeNode* root;
    BinaryTree(vector<int> nums) {
        root = new TreeNode(nums[0]);
        TreeNode* curr_root = root;
        
        queue < pair<TreeNode* , int> > qu;
        qu.push({root,0});

        while(!qu.empty()) {
            pair topEle = qu.front();
            qu.pop();
            int index = topEle.second;
            
            if(2*index + 1 < nums.size() and nums[2*index + 1] != null) {
                TreeNode* left_child = new TreeNode(nums[2*index + 1]);
                topEle.first->left = left_child;
                qu.push({left_child,2*index + 1});
            }
            else if(nums[2*index+1] == null) {
                topEle.first->left = NULL;
            }
            
            if(2*index + 2 < nums.size() and nums[2*index + 2] != null) {
                TreeNode* right_child = new TreeNode(nums[2*index + 2]);
                topEle.first->right = right_child;
                qu.push({right_child,2*index + 2});
            }
            else if(nums[2*index+2] == null) {
                topEle.first->right = NULL;
            }
        }
    }

    TreeNode* getRoot() {
        return this->root;
    }
};

int findLevels(TreeNode* root) {
    if(root == NULL) return 0;
    else return 1 + max(findLevels(root->left), findLevels(root->right));
}

void preOrderTraversal(TreeNode* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void levelOrderUsingQueue(TreeNode* root) {
    queue < pair< TreeNode*, int > > qu;
    qu.push({root,0});  
    int levels = findLevels(root);
    int n = pow(2,levels)-1;

    int count = 1;
    int power = 1;

    while(qu.size() > 0) {
        auto temp = qu.front();
        qu.pop();
        
        if(temp.first->val == null) {
            cout << "null ";
            count++;
            continue;
        }
        else cout << temp.first->val << " ";

        if(count == pow(2,power)-1 and power != 1) {
            cout << endl;
            power++;
            count++;
        }
        else if(power == 1) {
            cout << endl;
            power++;
            count++;
        }
        else count++;

        if(temp.first->left != NULL) qu.push({temp.first->left,2*temp.second+1});
        else {
            if(2*temp.second+1 < n) qu.push({new TreeNode(null),2*temp.second+1});
        }
        
        if(temp.first->right != NULL) qu.push({temp.first->right,2*temp.second+2});
        else {
            if(2*temp.second+2 < n) qu.push({new TreeNode(null),2*temp.second+2});
        }

    }
    cout << endl;
}

// Do not modify anything above this, Above code is used to convert array to binary tree and get root, so that we can
// solve leetcode question in VS Code itself.



int main() {
    vector<int> nums = {1,2,2,null,3,null,3,null,null,null,4,null,null,5,6};
    BinaryTree BT(nums);
    TreeNode* root = BT.getRoot();

    cout << "Entered Binary Tree -> " << endl;
    levelOrderUsingQueue(root);

    // dont change anything above this main
    
}

