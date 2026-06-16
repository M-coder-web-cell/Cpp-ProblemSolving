#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    Node* prev;
    Node* next;
}Node;

Node* head = NULL;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertBeforeHead(int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAfterLast(int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(Node* given, int data){
    if(given == NULL) return;
    Node* newNode = createNode(data);
    newNode->next = given->next;
    newNode->prev = given;

    if(given->next != NULL) given->next->prev = newNode;

    given->next = newNode;
}

void insertBefore(Node* given, int data){
    if(given == NULL) return;
    Node* newNode = createNode(data);
    newNode->prev = given->prev;
    newNode->next = given;

    if(given->prev != NULL) given ->prev->next = newNode;

    given->prev = newNode;
    if(given == head) head = newNode;
}

void deleteFirst(){
    if(head->next == NULL){
        free(head);
        return;
    }
    head = head->next;
    free(head->prev);
    head->prev = NULL;
}

void deleteGiven(Node* given){
    Node* temp = given;
    if(temp->prev){
        temp->prev->next = temp->next;
    }
    if(temp->next){
        temp->next->prev = temp->prev;
    }
    free(temp);
}

//Arranging pointers so that in the next the order followed is ascending

void arrangePointers(){
    int counter = 0;

    Node * temp = head;
    while(temp->next != NULL){
        counter+=1;
        temp = temp->next;
    }
    counter+=1;
    Node** arr = (Node**)malloc(counter* sizeof(Node));
    while(temp->next != NULL){
        temp = temp->next;
        arr 
    }

}