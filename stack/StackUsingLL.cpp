#include <iostream>

using namespace std;
class node{
    public:
    int value;
    node* next;
    node(int val){
        value = val;
        next = NULL;
    }
    void setNext(node* nextptr){
        next = nextptr;
    }
};

class Stack{
    node* top;

    public:
    Stack(int val){
        node newnode(val);
        node* newnodeptr = &newnode;
        top = newnodeptr;
    }

    void push(int val){
        node newnode(val);
        newnode.setNext(top);
        top = &newnode;
        cout<< "Sucessfully pushed the element "<<val<<" in to the stack\n";
    }

    int peek(){
        cout<< "the top element is "<<top->value;
        return top->value;

    }

};

int main(){
    Stack S(4);
    S.push(6);
    S.peek();
    return 0;
}