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

void Inorder(TreeNode*root, int& sum, vector<int>& nodes, int target, vector<vector<int>>& paths){
    if(root == NULL) {
        if(sum == target) paths.push_back(nodes);
        return;
    }

    sum+=root->val;
    nodes.push_back(root->val);
    Inorder(root->left, sum, nodes, target, paths);
    Inorder(root->right, sum, nodes, target, paths);

    sum-=root->val;
    nodes.pop_back();

}