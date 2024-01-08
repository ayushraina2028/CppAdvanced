#include <bits/stdc++.h>
using namespace std;

class TreeNode {

public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        this->val = value;
        this->left = NULL;
        this->right = NULL;
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

int main() {
    
    // constructing Tree
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    // connecting
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    vector<vector<int>> nodes;
    int levels = findLevels(a);
    
    nodes.resize(levels);
    levelOrderTraversal(a,nodes,0);

    for(auto row : nodes) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }
}