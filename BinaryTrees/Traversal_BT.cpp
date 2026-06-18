#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

void inOrder(Node* node){
    if(node == NULL) return;
    inOrder(node->left);
    cout<< node->data;
    inOrder(node->right);
}

void preOrder(Node* node){
    if(node == NULL) return;
    cout<<node->data;
    preOrder(node->left);
    preOrder(node->right);
}

vector<vector<int>> LevelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == NULL)return ans;
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i< size; i++){
            Node * node = q.front();
            q.pop();
            if(node->left != NULL)q.push(node->left);
            if(node->right != NULL)q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}