#include <iostream>
#include <vector>
# define red "red"
# define black "black"
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    string color; 

    TreeNode(int val, string color) {
        this->val = val;
        this->color = color;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

// Global root for Tree
TreeNode* root = new TreeNode(8, black);

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

void inOrderTraversal(TreeNode* root) {
    if(root == NULL) return;
    inOrderTraversal(root->left);
    cout << "(" << root->val << "->" << root->color << ")" << "  ";
    inOrderTraversal(root->right);
}

// function to insert into tree as normal BST
TreeNode* insertIntoRedBlackTree(TreeNode* root, TreeNode* node) {
    if(root == NULL) {
        return node;
    }

    else if(node->val < root->val) {
        if(root->left == NULL) {
            root->left = node;
            root->left->parent = root; // Socho ye kya hua
            return root;
        }
        else {
            insertIntoRedBlackTree(root->left, node);
        }
    }

    else if(node->val > root->val) {
        if(root->right == NULL) {
            root->right = node;
            root->right->parent = root; // Socho ye kya hua
            return root;
        }
        else {
            insertIntoRedBlackTree(root->right, node);
        }
    }

    return root;
}

void leftRotate(TreeNode* node) {

    TreeNode* temp = node->right;
    node->right = temp->left;

    // if right child is not none then add parent to it
    if(node->right) {
        node->right->parent = node;
    }

    // changing parent 
    temp->parent = node->parent;

    if(node->parent == NULL) {
        root = temp;
    }
    else if(node == node->parent->left) {
        node->parent->left = temp;
    }
    else if(node == node->parent->right) {
        node->parent->right = temp;
    }

    temp->left = node;
    node->parent = temp;

    
} 

void maintainProperty(TreeNode* root, TreeNode* node) {
    TreeNode* father = NULL;
    TreeNode* grandFather = NULL;

    // -> When your parent is red, you are red and parent is not root node do this work
    while((node != root) && (node->color != black) && (node->parent->color == red)) {
        
        // Initialize fathers and GrandFathers
        father = node->parent;
        grandFather = node->parent->parent;

        // Case -> A {father is left child of Grand Parent}
        if(father == grandFather->left) {
            TreeNode* uncle = grandFather->right;

            // Case I -> Uncle is Also Red
            if(uncle != NULL && uncle -> color == red) {
                father->color = black;
                uncle->color = black;
                if(grandFather != root) {
                    grandFather->color = red;
                }
            }
            // Uncle is black => 2 cases for left
            else {
                // to be continued

            }
        }

    }
}

int main() {
    // previous implementation was handmade, now for insertions we need to maintain a parent pointer also
    // We will create Red Black Tree from an array
    // Initially in the Tree Nodes will be added as red and then some operations will be performed to 
    // make it Red Black Tree

    TreeNode* a = new TreeNode(18, red);
    TreeNode* b = new TreeNode(5, red);
    TreeNode* c = new TreeNode(15, red);
    TreeNode* d = new TreeNode(17, red);
    TreeNode* e = new TreeNode(25, red);
    TreeNode* f = new TreeNode(40, red);
    TreeNode* g = new TreeNode(80, red);

    insertIntoRedBlackTree(root,a);
    insertIntoRedBlackTree(root, b);
    insertIntoRedBlackTree(root, c);

    

    int n = findLevels(root);

    // Level Order Print
    cout << "Level Order Print";
    for(int i = 0;i < n+1;i++) {
        print(root,1,i);
        cout << endl;
    }

    // Inorder to verify
    cout << "Inorder Traversal" << endl;
    inOrderTraversal(root);
    cout << endl;

    

}