#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};


int isEmpty(struct Queue *ptr){
    if (ptr->rear == ptr->front){
        return 1;
    }
    return 0;
}
// (*ptr).top
int isFull(struct Queue *ptr){
    if (ptr->rear==ptr->size-1){
        return 1;
    }
    return 0;
}
int r_enq(struct Queue *q,int value){
    if (isFull(q)){
        printf("Queue overflow\n");
        return 0;
    }
    q->rear++;
    q->arr[q->rear]=value;
    return 1;
}
int f_enq(struct Queue *q,int value){
    // If queue is empty, insert like rear enqueue to index 0
    if (isEmpty(q)){
        q->rear++;
        q->arr[q->rear]=value;
        return 1;
    }
    // Can only insert at front if there is free slot at index q->front
    if (q->front < 0){
        printf("Queue overflow at front\n");
        return 0;
    }
    q->arr[q->front]=value;
    q->front--;
    return 1;
}

int f_deq(struct Queue *q){
    int a=-1;
    if (isEmpty(q)){
        printf("Queue underflow\n");
    }
    else{
        q->front++;
        a=q->arr[q->front];
    }
    return a;
}
int r_deq(struct Queue *q){
    int a=-1;
    if (isEmpty(q)){
        printf("Queue underflow\n");
    }
    else{
        a=q->arr[q->rear];
        q->rear--;
    }
    return a;
}
int main(){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size=6;
    q->rear=-1;
    q->front=-1;
    q->arr=(int *)malloc(q->size*sizeof(int));

    r_enq(q,23);
    r_enq(q,45);
    r_enq(q,54);
    r_enq(q,65);
    r_enq(q,50);
    r_enq(q,100);

    printf("here's the first f_deqd value: %d\n",f_deq(q));
    printf("here's the second f_deqd value: %d\n",r_deq(q));

    f_enq(q, 25);
    f_enq(q,43);

    printf("here's the last element r_deqd value: %d\n",r_deq(q));
    printf("here's the second last element r_deqd value: %d\n",r_deq(q));
    
    if (isEmpty(q)){
        printf("Queue underflow\n");
    }
    else if (isFull(q)){
        printf("Queue overflow\n");
    }
    else{
        printf("Everything normal\n");
    }
    return 0;
}