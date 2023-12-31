#include <iostream>
#include <string>
#define red "red"
#define black "black"

using namespace std;

class TreeNode {

public:

    string color;
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    // constructor
    TreeNode(int val, string color) {
        this->value = val;
        this->color = color;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

// Global root for Tree
TreeNode* root = new TreeNode(11, black);

// left rotation
void leftRotate(TreeNode* node) {

    // make right child's -> left child as node's right child
    TreeNode* rightNode = node->right;
    node->right = rightNode->left;

    // UPDATE parent pointer of above assigned to node's right child, if not null
    if (rightNode->left != NULL) {
        rightNode->left->parent = node;
    }

    // parent of node becomes parent of node's right child
    rightNode->parent = node->parent;

    // now we have 3 cases
    if(node->parent == NULL) {
        root = rightNode;
    }
    else if(node == node->parent->left) { // when node is left child
        node->parent->left = rightNode;
    }
    else if(node == node->parent->right) {  // when node is right child
        node->parent->right = rightNode;
    }

    // remainings
    rightNode->left = node;
    node->parent = rightNode;

}

void rightRotate(TreeNode* node) {

    // make left child's -> right child as node's left child
    TreeNode* leftNode = node->left;
    node->left = leftNode->right;

    // UPDATE parent pointer of above assigned to node's left child, if not null
    if(leftNode->right != NULL) {
        leftNode->right->parent = node;
    }

    // parent of node becomes parent of node's left child
    leftNode->parent = node->parent;

    // again 3 cases
    if(node->parent == NULL) {
        root = leftNode;
    }
    else if(node == node->parent->left) {
        node->parent->left = leftNode;
    }
    else if(node == node->parent->right) {
        node->parent->right = leftNode;
    }

    // remainings
    leftNode->right = node;
    node->parent = leftNode;
}

void insertfix(TreeNode* node) {

    // keep fixing until properties are fixed.
    while(node->parent->color == red) {
        
        // check if node's parent is left child of grandfather
        if(node->parent->parent != NULL and node->parent == node->parent->parent->left) {
            
            TreeNode* grandfather = node->parent->parent;
            TreeNode* uncle = grandfather->right;

            // when uncle and parent both are red;
            if(uncle->color == red) {
                node->parent->color = black;
                uncle->color = black;
                grandfather->color = red;
                node = grandfather;
            }

            else { // when parent is red and uncle is black

                // if node is right child of parent
                if(node == node->parent->right) {

                    // set parent for left rotation
                    node = node->parent;
                    leftRotate(node);

                }

                // if it is left child then proceed without performing above step
                node->parent->color = black;
                node->parent->parent->color = red;
                rightRotate(node->parent->parent);
            }

        }

        else { // check when node's parent is right child of grandfather
            TreeNode* grandfather = node->parent->parent;
            TreeNode* uncle = grandfather->left;

            // when uncle and parent both are red
            if(uncle->color == red) {
                node->parent->color = black;
                uncle->color = black;
                grandfather->color = red;
                node = grandfather;
            }

            else { // when parent is red and uncle is black

                // if node is left child of parent
                if(node == node->parent->left) {

                    // set node for right rotate
                    node = node->parent;
                    rightRotate(node);

                }

                else { // if it is right child then skip above step
                    node->parent->color = black;
                    node->parent->parent->color = red;
                    leftRotate(node->parent->parent);                
                }

            }
        }

        if(node == root) break;

    }

    root->color = black;

}

void insert(TreeNode* node, TreeNode* root) {

    if(node->value < root->value and root->left == NULL) {
        root->left = node;
        node->parent = root;
    }

    else if(node->value < root->value and root->left != NULL) {
        return insert(node, root->left);
    }

    else if(node->value > root->value and root->right == NULL) {
        root->right = node;
        node->parent = root;
    }    

    else if(node->value > root->value and root->right != NULL) {
        return insert(node, root->right);
    }

    insertfix(node);
}

int findLevels(TreeNode* root) {
    if(root == NULL) return 0;
    int levels = 1 + max(findLevels(root->left), findLevels(root->right));
    return levels;
}

void print(TreeNode* root,int curr_level,int level) {
    if(root == NULL) return;
    
    // we tried by preorder, we can do by inOrder and post order also
    if(curr_level == level) {
        cout << "(" << root->value << "->" << root->color << ")" << "  ";
    }

    print(root->left, curr_level+1, level);
    print(root->right, curr_level+1, level);
 
}


void inOrderTraversal(TreeNode* root) {
    if(root == NULL) return;
    inOrderTraversal(root->left);
    cout << "(" << root->value << "->" << root->color << ")" << "  ";
    inOrderTraversal(root->right);
}

int main() {

    

    // Nodes to be added in order
    TreeNode* a = new TreeNode(2, red);
    TreeNode* b = new TreeNode(14, red);
    TreeNode* c = new TreeNode(1, red);
    TreeNode* d = new TreeNode(7, red);
    TreeNode* e = new TreeNode(15, red);
    TreeNode* f = new TreeNode(5, red);
    TreeNode* g = new TreeNode(8, red);
    TreeNode* h = new TreeNode(4, red);

    insert(a, root);
    insert(b, root);
    insert(c, root);
    insert(d, root);
    insert(e, root);
    insert(f, root);
    insert(g, root);
    insert(h, root);

    int n = findLevels(root);

    // Level Order Print
    cout << "Level Order Print";
    for(int i = 0;i < n+1;i++) {
        print(root,1,i);
        cout << endl;
    }
}