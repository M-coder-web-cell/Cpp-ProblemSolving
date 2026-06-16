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


int height(TreeNode* root, int& maxD){

    if(root == NULL) return 0;

    int l = height(root->left, maxD);
    int r = height(root->right, maxD);

    maxD = max(maxD, l+r);
    return 1 + max(l, r);
}

int diameterOfBinaryTree(TreeNode* root){
    int maxD = 0;
    int maxh = height(root, maxD);

    return maxD;
}