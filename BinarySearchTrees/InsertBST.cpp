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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    TreeNode* curr = root;

    while(true){
        if(curr->val <= val){
            if(curr->right != NULL) curr = curr->right;
            else {
                curr->right = new TreeNode(val);
                break;
            }
        }else {
            if(curr->left != NULL) curr = curr->left;
            else {
                curr->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}