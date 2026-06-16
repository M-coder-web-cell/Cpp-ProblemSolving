#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left, *right;

    Node(int value){
        val = value;
        left = right = NULL;
    }
};

vector<int> PreOrderUsingStack(Node* root){
    vector<int> preOrder;
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();
        preOrder.push_back(root->val);
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);

    }
    return preOrder;
}