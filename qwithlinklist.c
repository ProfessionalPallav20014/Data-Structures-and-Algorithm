#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *f;
    struct Node *r;
};

int isEmpty(struct Node *f){
    if (f==NULL){
        return 1;
    }
    return 0;
}

int isFull(struct Node *ptr){
    if (ptr==NULL){
        return 1;
    }
    return 0;
}

void enq(struct Node *r,struct Node *f,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=NULL;
    
}
int main(){
    
    return 0;
}