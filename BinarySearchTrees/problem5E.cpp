#include <iostream>
#include <vector>
#include <climits>
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

void inOrderTraversal(TreeNode* root) {
    if(root==NULL) return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

TreeNode* constructBinarySearchTree(vector <int>& preOrder, int& index, int l_bound, int u_bound) {
    
    // -> Base Case I
    if(index >= preOrder.size()) return NULL;

    TreeNode* root = NULL;
    int key = preOrder[index];
    if(key < u_bound && key > l_bound) {
        root = new TreeNode(key);
        index++;

        // Here only call next 
        if(index < preOrder.size()) {
            root->left = constructBinarySearchTree(preOrder, index, l_bound, root->val);
        }

        if(index < preOrder.size()) {
            root->right = constructBinarySearchTree(preOrder, index, root->val, u_bound);
        }
    }

    return root;
}

int main() {
    // We need to construct our Binary Search Tree from its PreOrder Traversal in O(n) time
    vector <int> preOrder = {4,2,1,3,7,5,8};
    int index = 0;
    TreeNode* root = constructBinarySearchTree(preOrder, index, INT_MIN, INT_MAX);


    // Checking Correctness by Inorder traversal
    inOrderTraversal(root);
}