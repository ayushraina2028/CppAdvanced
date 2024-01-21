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

void spread(TreeNode* root,int& leftSpread, int& rightSpread, int i, int j) {
    if(root == NULL) return;
    rightSpread = max(rightSpread,j);
    leftSpread = min(leftSpread,j);

    spread(root->left,leftSpread, rightSpread, i+1,j-1);
    spread(root->right,leftSpread,rightSpread,i+1,j+1);

    return;
}

void inorderTravel(TreeNode* root, int x, int y, int gap, vector<vector<int>>& answer) {
    if(root==NULL) {
        return;
    }

    inorderTravel(root->left,x+1,y-1,gap,answer);
    answer[y+gap].push_back(root->val);
    inorderTravel(root->right,x+1,y+1,gap,answer);

    return;
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> answer;
    int leftSpread = 0;
    int rightSpread = 0;

    spread(root,leftSpread,rightSpread,0,0);
    cout << leftSpread << " " << rightSpread << endl;

    int gap = abs(leftSpread);
    answer.resize(1+abs(leftSpread)+rightSpread);
    inorderTravel(root,0,0,gap,answer);

    for(int i = 0;i < answer.size(); i++) {
        sort(answer[i].begin(), answer[i].end());
    }
    return answer;
}

int main() {
    vector<int> nums = {3,1,4,0,2,2};
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
    cout << endl << "*************************" << endl << endl;
    vector<vector<int>> vertical = verticalTraversal(root);

    cout << endl;
    for(auto row : vertical) {
        for(auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}   