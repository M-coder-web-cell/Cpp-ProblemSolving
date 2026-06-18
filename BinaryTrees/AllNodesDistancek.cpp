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

unordered_map<TreeNode*, TreeNode*> parentMap;
// Helper function to map each node to its parent
void buildParentMap(TreeNode* node, TreeNode* parent) {
    if (!node) return;
    if (parent) {
        parentMap[node] = parent;
    }
    buildParentMap(node->left, node);
    buildParentMap(node->right, node);
}

vector<int> performBFS(TreeNode* root, int k){
    queue<TreeNode*> q;
    unordered_set<TreeNode*> visited;

    while(!q.empty()){

        if(k==0){
            vector<int> result;
            while (!q.empty()) {
                result.push_back(q.front()->val);
                q.pop();
            }
            return result;           
        }
        int size = q.size();
        // Process the current level
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            
            // First add its children to the queue (if unvisited)
            if (curr->left && visited.find(curr->left) == visited.end()) {
                visited.insert(curr->left);
                q.push(curr->left);
            }
            if (curr->right && visited.find(curr->right) == visited.end()) {
                visited.insert(curr->right);
                q.push(curr->right);
            }
            
            // Then add its parent to the queue (if unvisited)
            if (parentMap.count(curr) && visited.find(parentMap[curr]) == visited.end()) {
                visited.insert(parentMap[curr]);
                q.push(parentMap[curr]);
            }
        }
        // Decrement distance after finishing the current level
        k--; 
    }
    return {};
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    buildParentMap(root, nullptr);
    return performBFS(target, k);
}