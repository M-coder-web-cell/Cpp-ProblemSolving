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

int main(){
    int a;
    cin>> a;
    queue <Node*> q;
    Node *root = new Node(a);
    q.push(root);

    while(!q.empty()){
        int x,y;
        Node* temp = q.front();
        q.pop();

        cin>>x; //left
        if(x!=-1){
            temp->left = new Node(x);
            q.push(temp->left);
        }
        cin>>y; //right
        if(x!=-1){
            temp->right = new Node(y);
            q.push(temp->right);
        }
    }
    return 0;
}