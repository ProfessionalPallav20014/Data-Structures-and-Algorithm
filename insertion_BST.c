# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void insertion(struct Node *root, int key){
    struct Node *prev=NULL;
    while (root!=NULL){
        prev=root;
        if (key==root->data){
            printf("Duplicate element detected, insertion can'be be performed\n");
            return;
        }
        else if (key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct Node * new=createNode(key);
    if (key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
    }

}

int main(){
    struct Node *p=createNode(5);
    struct Node *p2=createNode(3);
    struct Node *p3=createNode(7);
    struct Node *p4=createNode(1);
    struct Node *p5=createNode(4);
    struct Node *p6=createNode(8);

    /* This is the tree
            5
            /\
           3  7
           /\  \
          1  4  8 
    */


    p->left=p2;
    p->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->right=p6;

    insertion(p,6);
    printf("%d",p->right->left->data);
    return 0;
}