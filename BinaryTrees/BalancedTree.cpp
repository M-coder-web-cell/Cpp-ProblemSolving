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

int maxheight(Node*root, int& valid){

    if(root == NULL) return 0;

    int l = maxheight(root->left, valid);
    int r = maxheight(root->right, valid);

    if(abs(l-r) > 1) valid = 0;

    return 1+max(l,r);
}

bool isBalanced(Node* root){
    int valid = 1;
    int maxh = maxheight(root, valid);
    return (bool)valid;

}