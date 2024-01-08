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
            continue;
        }
        else cout << temp.first->val << " ";

        if(count == pow(2,power)-1 and power != 0) {
            cout << endl;
            power++;
            count++;
        }
        else if(power == 0) {
            cout << endl;
            count++;
            power++;
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
// Just Copy paste below function on leetcode and it will get accepted.

bool isSameTree(TreeNode* root1, TreeNode* root2) {

    if(root1 == NULL and root2 == NULL) return true;
    else if((root1 == NULL and root2 != NULL) or (root1 != NULL and root2 == NULL) or (root1->val != root2->val)) return false;

    if(!isSameTree(root1->left, root2->left) or !isSameTree(root1->right, root2->right)) return false;

    return true;
}

int main() {
    vector<int> nums1 = {1,2};
    BinaryTree BT1(nums1);
    TreeNode* root1 = BT1.getRoot();

    cout << "Entered Binary Tree 1-> " << endl;
    levelOrderUsingQueue(root1);

    vector<int> nums2 = {1,null,2};
    BinaryTree BT2(nums2);
    TreeNode* root2 = BT2.getRoot();

    cout << "Entered Binary Tree 2-> " << endl;
    levelOrderUsingQueue(root2);

    // dont change anything above this main
    bool ans = isSameTree(root1,root2);
    if(ans) cout << "Both trees are same " << endl;
    else cout << "Trees are not same " << endl;
}

