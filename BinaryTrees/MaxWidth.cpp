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


int widthOfBinaryTree(TreeNode* root) {
    
    //LEVEL ORDER TRAVERSAL
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});
    unsigned long long maxw = 0;

    while(!q.empty()){
        int size = q.size();
        unsigned long long levell = q.front().second; // First element's index
        unsigned long long levelr = q.back().second;  // Last element's index
        maxw = max(maxw, levelr - levell + 1);

        for(int i = 0; i<size; i++){
            TreeNode* node = q.front().first;
            unsigned long long idx = q.front().second - levell; 
            q.pop();

            if (node->left) {
                q.push({node->left, 2*idx+1});
            } 

            // Right child logic
            if (node->right) {
                q.push({node->right, 2*idx+2});
            }
        }

    }
    return maxw;
}