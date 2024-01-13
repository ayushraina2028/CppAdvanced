#include <iostream>
#include <vector>
#include <queue>
#define null -2346429
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

void levelOrderTraversal(TreeNode* root) {
    queue< TreeNode* > qu;
    qu.push(root);

    while(qu.size() > 0) {
        TreeNode* node = qu.front();
        qu.pop();

        cout << node->val << " ";
        if(node->left != NULL) qu.push(node->left);
        if(node->right != NULL) qu.push(node->right);
    }

    cout << endl;
}

TreeNode* constructBT(vector<int>& nums) {
    queue < TreeNode* > qu;
    TreeNode* root = new TreeNode(nums[0]);
    qu.push(root);

    // Base cases;
    if(nums.size() == 1) return root;
    else if(nums.size() == 2) {
        if(nums[1] == null) return root;
        else root->left = new TreeNode(nums[1]);
        return root;
    }
    else if(nums.size()==3) {
        if(nums[1]==null) root->left = NULL;
        else root->left = new TreeNode(nums[1]);

        if(nums[2]==null) root->right = NULL;
        else root->right = new TreeNode(nums[2]);

        return root;
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

    return root;
}

// DO NOT MODIFY anything above this;

int minDepth(TreeNode* root) {

    if(root == NULL) return 0;
    if(root->left == NULL and root->right == NULL) return 1;
    
    int answer = 1;
    if(root->left != NULL and root->right != NULL) {
        answer += min(minDepth(root->left), minDepth(root->right));
    }

    else if(root->left == NULL and root->right != NULL) {
        answer += minDepth(root->right);
    }

    else if(root->left != NULL and root->right == NULL){
        answer += minDepth(root->left);
    }

    else return 0;

    return answer;
}

int main() {
    vector<int> nums = {3,9,20,null,null,15,7};
    TreeNode* root = constructBT(nums);
    cout << "Entered Binary Tree -> ";
    levelOrderTraversal(root);

    // DO NOT modify anything above this
    int minimumDepth = minDepth(root);
    cout << "Minimum depth: " << minimumDepth << endl;
}   