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
void postorder_traversal(struct Node *root){
    if (root!=NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ",root->data);
    }
}
void inorder_traversal(struct Node *root){
    if (root!=NULL){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}
int is_BST(struct Node *root){
    static struct Node *prev=NULL;
    if (root!=NULL){
        if (!is_BST(root->left)){
            return 0;
        }
        if (prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return is_BST(root->right);
    }
    else 
        return 1;
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

    preorder_traversal(p);
    printf("\n");
    postorder_traversal(p);
    printf("\n");
    inorder_traversal(p);
    return 0;
}