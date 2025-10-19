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
void inorder_traversal(struct Node *root){
    if (root!=NULL){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}
struct Node * inorderPredecessor(struct Node *root){
    root=root->left;
    while (root->right != NULL){
        root=root->right;
    }
    return root;
}
struct Node *deletion(struct Node *root, int value){
    if (root== NULL){
        return NULL;
    }
    // search node to be deleted
    if (value < root->data){
        root->left=deletion(root->left, value);
    }
    else if (value > root->data){
        root->right=deletion(root->right, value);
    }
    // make strategy to delete.
    else{
        if (root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        struct Node * iPre=inorderPredecessor(root);
        root->data=iPre->data;
        root->left=deletion(root->left, iPre->data);
    }
    return root;
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

    inorder_traversal(p);
    printf("\n");
    deletion(p,7);
    inorder_traversal(p);
    return 0;
} 