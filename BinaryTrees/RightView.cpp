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

vector<int> rightSideView(TreeNode* root){
    vector<vector<int>> res;
    vector<int> out;
    if(root == NULL) return out;
    queue <TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i = 0; i<size; i++){
            TreeNode*  node = q.front();
            if(i == size - 1)row.push_back(node->val);
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(row);
    }

    for(auto item : res){
        out.push_back(item[0]);
    }

    return out;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    vector<int> res = rightSideView(root);

    for(int num : res){
        cout << num <<" ";
    }
    delete root;
    return 0;
}