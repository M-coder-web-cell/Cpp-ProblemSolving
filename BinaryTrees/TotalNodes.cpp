#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int TotalNodes(Node* root){
    if(root == NULL) return 0;
    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(6);

    cout<< TotalNodes(root)<< endl;
    delete root;
    return 0;
}