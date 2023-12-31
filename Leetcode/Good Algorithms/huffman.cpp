#include <iostream>
#include <queue>
#include <unordered_map>
#define pp pair<int, string>

using namespace std;

class Compare {
public:
    bool operator()(const pp pair1, const pp pair2) {
        return pair1.first > pair2.first;
    }
};

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    string s;

    // constructor
    TreeNode(int value, string str) {
        this->val = value;
        this->left = NULL;
        this->right = NULL;
        this->s = str;
    }
};

TreeNode* joinTreeNodes(TreeNode* Node1, TreeNode* Node2) {
    TreeNode* root = new TreeNode(Node1->val+Node2->val, Node1->s + Node2->s);
    root->left = Node1;
    root->right = Node2;
    return root;
}

void display_queue(priority_queue< pp , vector<pp>, Compare> pq) {
    while(!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    cout << endl;
    return;
}

TreeNode* huffmanCodes(vector <pair <string, int>> arr) {

    // declaring priority queue
    priority_queue<pp, vector <pp>, Compare > pq;
    TreeNode* root;
    TreeNode* x;
    TreeNode* y;
    unordered_map< int, TreeNode* > map;

    for(auto ele : arr) {
        pq.push({ele.second, ele.first});
    }

    while(pq.size() > 1) {

        display_queue(pq);

        pp a = pq.top();
        pq.pop();

        pp b = pq.top();
        pq.pop();

        if(map.find(a.first) != map.end()) {
            x = map[a.first];
        }
        else {
            x = new TreeNode(a.first, a.second);
        }
       
        if(map.find(b.first) != map.end()) {
            y = map[b.first];
        }
        else {
            y = new TreeNode(b.first, b.second);
        }
        
        root = joinTreeNodes(x,y);
        map[x->val+y->val] = root;
        pq.push({a.first+b.first, a.second+b.second});
    }

    // now binary tree is constructed.
    return root;
}

void preOrderTraversal(TreeNode* root) {
    if(root == NULL) return;

    cout << root->val << " -> " << root->s << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void printCodes(TreeNode* root, string str) {

    if(root->left != NULL) {
        printCodes(root->left,str+"0");
    }
    else {
        cout << root->s << " -> " << str << endl;
        return;
    }

    if(root->right != NULL) {
        printCodes(root->right, str+"1");
    }
    else {
        cout << root->s << " -> " << str << endl;
        return;
    }

}

int main() {
    // declaration and inputs
    vector <pair <string,int> > v = {{"a",5}, {"b",9}, {"c",12}, {"d",13}, {"e",16}, {"f",45}};
    
    // Binary Tree is Constructed.
    TreeNode* root = huffmanCodes(v);

    // preOrder traversal to check the ready tree.
    preOrderTraversal(root);
    cout << endl;
    cout << endl;

    //print Huffman Codes
    printCodes(root,"");

}