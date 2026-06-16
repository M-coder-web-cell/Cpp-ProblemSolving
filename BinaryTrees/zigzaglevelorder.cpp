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

vector<vector<int>> zigzaglevelorder(TreeNode* root){
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    bool lefttoright = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i = 0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            int index = (lefttoright)? i : size-i-1;
            row[index] = node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        lefttoright = !lefttoright;
        res.push_back(row);
    }
    return res;
}

void print2DVector(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << "\n";
    }
}

int main(){
    TreeNode*root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = zigzaglevelorder(root);
    print2DVector(res);
    delete root;
    return 0;
}