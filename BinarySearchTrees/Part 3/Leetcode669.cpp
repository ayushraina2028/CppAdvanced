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
        queue < TreeNode* > qu;
        this->root = new TreeNode(nums[0]);
        qu.push(root);

        // Base cases;
        if(nums.size() == 1) return;
        else if(nums.size() == 2) {
            if(nums[1] == null) return;
            else root->left = new TreeNode(nums[1]);
            return;
        }
        else if(nums.size()==3) {
            if(nums[1]==null) root->left = NULL;
            else root->left = new TreeNode(nums[1]);

            if(nums[2]==null) root->right = NULL;
            else root->right = new TreeNode(nums[2]);

            return;
        }

        // when > 3 nodes
        int i = 1, j = 2;
        while(qu.size() > 0 and i < nums.size()) {
            TreeNode* node = qu.front();
            qu.pop();

            TreeNode* leftNode;
            TreeNode* rightNode;

            if(nums[i] != null) leftNode = new TreeNode(nums[i]);
            else leftNode = NULL;

            if(j < nums.size() and nums[j] != null) rightNode = new TreeNode(nums[j]);
            else rightNode = NULL;

            node->left = leftNode;
            node->right = rightNode;

            if(leftNode != NULL) qu.push(leftNode);
            if(rightNode != NULL) qu.push(rightNode);

            i+=2;
            j+=2;

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


void levelOrderTraversal(TreeNode* root,vector<vector<int>>& nodes,int level) {

    if(root == NULL) return;

    nodes[level].push_back(root->val);
    if(root->left != NULL) levelOrderTraversal(root->left, nodes, level+1);
    if(root->right != NULL) levelOrderTraversal(root->right, nodes, level+1);
}


// Do not modify anything above this, Above code is used to convert array to binary tree and get root, so that we can
// solve leetcode question in VS Code itself.

void helper(TreeNode* root, int low, int high) {
    if(root == NULL) return;

    // Left call
    while(true) {
        if(root->left != NULL and root->left->val < low) {
            root->left = root->left->right;
        }
        else if(root->left != NULL and root->left->val > high) {
            root->left = root->left->left;
        }
        else break;
    }

    // Right Call
    while(true) {
        if(root->right != NULL and root->right->val > high) {
            root->right = root->right->left;
        }
        else if(root->right != NULL and root->right->val < low) {
            root->right = root->right->right;
        }
        else break;
    }

    // recurse
    helper(root->left,low,high);
    helper(root->right,low,high);
    return;
}

TreeNode* trimBST(TreeNode* root, int low, int high) {
    TreeNode* node = new TreeNode(INT_MAX);
    node->left = root;

    helper(node,low,high);

    return node->left;
}

int main() {
    vector<int> nums = {3,1,4,null,2};
    BinaryTree BT(nums);
    TreeNode* root = BT.getRoot();
    cout << "Entered Binary Tree -> " << endl;
    vector<vector<int>> nodes;
    int levels = findLevels(root);
    
    nodes.resize(levels);
    levelOrderTraversal(root,nodes,0);

    int count = 0;
    for(auto row : nodes) {
        cout << "Level " << count+1 << " -> ";
        for(auto x : row) cout << x << " ";
        count++;
        cout << endl;
    }

    // DO NOT modify anything above this
    int low = 3;
    int high = 4;
    int prev_val = 0;
    TreeNode* newRoot = trimBST(root,low,high);
    levels = findLevels(newRoot);

    nodes.clear();
    nodes.resize(levels);
    levelOrderTraversal(newRoot,nodes,0);

    cout << "Modified GST -> " << endl;
    count = 0;
    for(auto row : nodes) {
        cout << "Level " << count+1 << " -> ";
        for(auto x : row) cout << x << " ";
        count++;
        cout << endl;
    }
    
}   