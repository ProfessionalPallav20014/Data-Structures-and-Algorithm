#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int back;
    int *arr;
};


int isEmpty(struct Queue *ptr){
    if (ptr->back == ptr->front){
        return 1;
    }
    return 0;
}
// (*ptr).top
int isFull(struct Queue *ptr){
    if ((ptr->back+1)%ptr->size==ptr->front){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *q,int value){
    if (isFull(q)){
        printf("Queue overflow\n");
    }
    else{
        q->back=(q->back+1)%q->size;
        q->arr[q->back]=value;
    }
}
int dequeue(struct Queue *q){
    int a=-1;
    if (isEmpty(q)){
        printf("Queue underflow\n");
    }
    else{
        q->front=(q->front+1)%q->size;
        a=q->arr[q->front];
    }
    return a;
}
int main(){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size=6;
    q->back=0;
    q->front=0;
    q->arr=(int *)malloc(q->size*sizeof(int));

    enqueue(q,23);
    enqueue(q,45);
    enqueue(q,54);
    enqueue(q,65);
    enqueue(q,50);
    enqueue(q,100);
    enqueue(q,120);
    enqueue(q,140);

    printf("here's the first dequeued value: %d\n",dequeue(q));
    printf("here's the second dequeued value: %d\n",dequeue(q));
    printf("here's the third dequeued value: %d\n",dequeue(q));
    printf("here's the fourth dequeued value: %d\n",dequeue(q));
    
    if (isEmpty(q)){
        printf("Queue is empty\n");
    }
    else if (isFull(q)){
        printf("Queue is full\n");
    }
    else{
        printf("Everything normal\n");
    }
    return 0;
}