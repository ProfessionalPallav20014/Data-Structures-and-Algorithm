#include <stdio.h>
#include <stdlib.h>
 
struct Node *f=NULL; // make them global, so that their copies aren't passed
struct Node *r=NULL;
struct Node{
    int data;
    struct Node*next;
};

void linklistTraveresal(struct Node *ptr){
    while (ptr != NULL) {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enq(int val){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    if (ptr==NULL){
        printf("Queue overflow\n");
    }
    else{
        ptr->data=val;
        ptr->next=NULL;
        if (f==NULL){ //special condition 
            f=r=ptr;
        }
        else{
            r->next=ptr;
            r=ptr;
        }
    }
}

int deq(){
    int val=-1;
    struct Node *p=f;
    if (f==NULL){
        printf("Queue underflow\n");
    }
    else{
        f=f->next;
        val=p->data;
        free(p);
    }
    return val;
}

int main(){
    enq(32);
    enq(20);
    enq(45);
    enq(54);
    enq(98);
    printf("Here is the first dequeued element: %d\n",deq());
    printf("Here is the second dequeued element: %d\n",deq());
    linklistTraveresal(f);
    return 0;
}
