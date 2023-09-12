#include <iostream>
#include <vector>
# define red "red"
# define black "black"

using namespace std;


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    string color; 

    TreeNode(int val, string color) {
        this->val = val;
        this->color = color;
        this->left = NULL;
        this->right = NULL;
    }
};

int findLevels(TreeNode* root) {
    if(root == NULL) return 0;
    int levels = 1 + max(findLevels(root->left), findLevels(root->right));
    return levels;
}

void print(TreeNode* root,int curr_level,int level) {
    if(root == NULL) return;
    
    // we tried by preorder, we can do by inOrder and post order also
    if(curr_level == level) {
        cout << "(" << root->val << "->" << root->color << ")" << "  ";
    }

    print(root->left, curr_level+1, level);
    print(root->right, curr_level+1, level);

    
}

int main() {

    // Creating tree nodes: Tree => Level Order {13,8,17,1,11,15,25,6,22,27}
    TreeNode* a = new TreeNode(13, black);
    TreeNode* b = new TreeNode(8, red);
    TreeNode* c = new TreeNode(17, red);
    TreeNode* d = new TreeNode(1, black);
    TreeNode* e = new TreeNode(11, black);
    TreeNode* f = new TreeNode(15, black);
    TreeNode* g = new TreeNode(25, black);
    TreeNode* h = new TreeNode(6, red);
    TreeNode* i = new TreeNode(22, red);
    TreeNode* j = new TreeNode(27, red);

    // => Connecting TreeNodes
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    d->right = h;
    g->left = i;
    g->right = j;


    int n = findLevels(a);
    for(int i = 0;i < n+1;i++) {
        print(a,1,i);
        cout << endl;
    }
}