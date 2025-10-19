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

struct Node *searchIter(struct Node * root, int key){
    while (root!=NULL){
        if (root->data==key){
            return root;
        }
        else if(root->data>key){
           root=root->left;
        }
        else {
            root=root->right;
        }
    }
    return NULL;
}

int main(){
    struct Node *p=createNode(5);
    struct Node *p2=createNode(3);
    struct Node *p3=createNode(6);
    struct Node *p4=createNode(1);
    struct Node *p5=createNode(4);
    struct Node *p6=createNode(7);

    /* This is the tree
            5
            /\
           3  6
           /\  \
          1  4  7 
    */


    p->left=p2;
    p->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->right=p6;

    struct Node * n=searchIter(p,4);
    if (n!=NULL){
        printf("Found %d",n->data);
    }
    else{
        printf("Element not found");
    }

    return 0;
}