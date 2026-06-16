#include <bits/stdc++.h>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    if(root == p) return p;
    if(root == q) return q;

    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if(!l && !r) return NULL;
    if(l && !r) return l;
    if(!l && r) return r;
    if(l && r && (l != r)) {
        return root;
    } 

    return root;
}