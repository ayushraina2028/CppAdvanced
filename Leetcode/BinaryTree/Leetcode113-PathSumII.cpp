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

void f(TreeNode* root, int targetSum, vector<int>& v, vector<vector<int>>& answer) {
    if(root == NULL) return;
    else if(root->left == NULL and root->right == NULL and targetSum == root->val) {
        v.push_back(root->val);
        answer.push_back(v);
        v.pop_back();
        return;
    }
    else if(root->left == NULL and root->right == NULL and targetSum != root->val) return;

    v.push_back(root->val);
    targetSum -= root->val;

    f(root->left,targetSum,v,answer);
    f(root->right,targetSum,v,answer);

    v.pop_back();
    targetSum += root->val;

    return;

}

vector<vector<int>> pathSumII(TreeNode* root, int targetSum) {
    vector<vector<int>> answer;
    vector<int> v;

    f(root,targetSum,v,answer);

    return answer;
}

int main() {
    vector<int> nums = {5,4,8,11,null,13,4,7,2,null,null,5,1};
    BinaryTree BT(nums);
    TreeNode* root = BT.getRoot();
    cout << "Entered Binary Tree -> " << endl;
    vector<vector<int>> nodes;
    int levels = findLevels(root);
    
    nodes.resize(levels);
    levelOrderTraversal(root,nodes,0);

    for(auto row : nodes) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }

    // DO NOT modify anything above this

    int targetSum = 22;
    vector<vector<int>> answer = pathSumII(root,targetSum);
    int count = 1;
    for(auto row : answer) {
        cout << "Path " << count << " => ";
        for(auto x : row) cout << x << " ";
        cout << endl;
        count++;
    }
}   