#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
}; 

int findLevels(Node* root) {
        if(root == NULL) return 0;
        int levels = 1 + max(findLevels(root->left), findLevels(root->right));
        return levels;
    }

    void findLevelOrder(Node* root, vector <vector <int>>& answer,int level) {
        if(root == NULL) return;
        answer[level].push_back(root->val);
        findLevelOrder(root->left, answer, level+1);
        findLevelOrder(root->right, answer, level+1);
    }



int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);


    // Connecting
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    int n = findLevels(a);
    vector <vector <int>> finalAns;
    for(int i = 0;i < n;i++) {
        vector <int> v;
        finalAns.push_back(v);
    }
    findLevelOrder(a,finalAns,0);

    for(int i = 0;i < finalAns.size();i++) {
        for(int j = 0;j < finalAns[i].size();j++) {
            cout << finalAns[i][j] << " ";
        }
        cout << endl;
    }
}

