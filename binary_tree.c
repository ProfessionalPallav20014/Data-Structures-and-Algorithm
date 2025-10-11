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

void preorder_traversal(struct Node *root){
    if (root!=NULL){
        printf("%d ",root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

int main(){
    struct Node *p=createNode(2);
    struct Node *p2=createNode(1);
    struct Node *p3=createNode(4);
    struct Node *p4=createNode(11);
    struct Node *p5=createNode(12);
    struct Node *p6=createNode(3);

    /* This is the tree
            2
            /\
           1  4
           /\  \
          11 12 3
    */


    p->left=p2;
    p->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->right=p6;

    preorder_traversal(p);
    return 0;
}