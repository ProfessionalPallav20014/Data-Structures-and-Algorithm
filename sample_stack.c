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
struct Node *push(int data){
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
int pop(){
    if (isEmpty(top)){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        struct Node *p=top;
        top=top->next;
        int val=p->data;
        free(p);
        return val;
    }
}

int main(){
    push(12);
    push(28);
    push(56);
    push(48);
    push(45);
    linklistTraveresal(top);
    printf("First popped element is: %d\n",pop());
    printf("Second popped element is: %d\n",pop());
    linklistTraveresal(top);
    return 0;
}