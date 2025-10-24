#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int a, int b){
    return (a>b)?a:b;
}
int getHeight(struct Node *n){
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct Node * createNode(int key){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int getbalancefactor(struct Node * n){
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node * rightRotate(struct Node * y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct Node * leftRotate(struct Node * x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct Node * insertion(struct Node *node, int key){
    if (node == NULL)
    {
        return createNode(key);
    }
    if (key < node->key)
        node->left = insertion(node->left, key);
    else if (key > node->key)
        node->right = insertion(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getbalancefactor(node);

    // LL case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // RR case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // RL case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    // LR case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    return node;
}

void preorder_traversal(struct Node *root){
    if (root!=NULL){
        printf("%d ",root->key);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

int main(){
    struct Node *root=NULL;
    root=insertion(root, 1);
    root=insertion(root, 2);
    root=insertion(root, 4);
    root=insertion(root, 5);
    root=insertion(root, 6);
    root=insertion(root, 3);

    preorder_traversal(root);
    return 0;
}