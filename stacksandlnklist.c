# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};
struct Node * top=NULL;

void linklistTraveresal(struct Node *ptr){
    while (ptr != NULL) {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct Node *top){
    if (top==NULL){
        return 1;
    }
    return 0;
}
int isFull(struct Node *top){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    if (p==NULL){
        return 1;
    }
    return 0;
}
struct Node *push(struct Node *top, int data){
    if (isFull(top)){
        printf("Stack overflow\n");
        return top;
    }
    else{
        struct Node *p=(struct Node*)malloc(sizeof(struct Node));
        p->data=data;
        p->next=top;
        top=p;
        return top;
    }
}
int pop(struct Node *tp){
    if (isEmpty(tp)){
        printf("Stack underflow\n");
    }
    else{
        struct Node *p=tp;
        top=tp->next;
        int x=p->data;
        free(p);
        return x;
    }
}
int peek(int pos){
    struct Node *ptr=top;
    for (int i=0; (i<pos-1 && ptr!=NULL); i++){
        ptr=ptr->next;
    }
    if (ptr!=NULL){
        return ptr->data;
    }
    return -1;
}
int stackTop(struct Node* top){
    return top->data;
}
int stackBottom(struct Node *top){
    struct Node *p=top;
    while (p->next!=NULL){
        p=p->next;
    }
    return p->data;
}
int main(){
    top=push(top,45);
    top=push(top,56);
    top=push(top,89);
    top=push(top,12);
    printf("Here's the topmost element of the stack: %d\n",stackTop(top));
    printf("Here's the bottom-most element of the stack: %d\n",stackBottom(top));
    printf("Here's the element: %d\n",peek(3));
    return 0;
}