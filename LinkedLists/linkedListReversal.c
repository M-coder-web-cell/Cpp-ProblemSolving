#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    Node* next;
    int val;
}Node;

Node* head = NULL;

Node* createNode(int val){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->val = val;
}
void ReverseLinkedList(){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

}

int main(){
    
}