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

void leftBoundary(TreeNode* root) {
    TreeNode* node = root;
    cout << node->val << " ";
    
    while(node->left) {
        node = node->left;
        cout << node->val << " ";
    }

    if(node->right) node = node->right;
    else return;

    if(node->left == NULL and node->right == NULL) return;
    else leftBoundary(node);

    return; 
}

void bottomBoundary(TreeNode* root) {
    if(root == NULL) return;

    if(root->left == NULL and root->right == NULL) cout << root->val << " ";
    bottomBoundary(root->left);
    bottomBoundary(root->right);

    return;
}

void rightBoundary(TreeNode* root) {
    TreeNode* node = root;
    cout << node->val << " ";
    
    while(node->right) {
        node = node->right;
        cout << node->val << " ";
    }

    if(node->left) node = node->left;
    else return;

    if(node->left == NULL and node->right == NULL) return;
    else rightBoundary(node);

    return; 
}

int main() {
    vector<int> nums = {1,2,3,4,5,null,6,7,null,8,null,9,10,null,11,null,12,null,13,null,14,15,16,null,17,null,null,18,null,19,null,null,null,20,21,22,23,null,24,25,26,27,null,null,28,null,null};
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
    cout << endl << "Left Boundary -> ";
    leftBoundary(root);
    cout << endl;

    cout << "Bottom Boundary -> ";
    bottomBoundary(root);
    cout << endl;

    if(root->right) {
        cout << "Right Boundary -> ";
        rightBoundary(root->right);
        cout << endl;
    }
    else cout << "No right Boundary";

    
}   