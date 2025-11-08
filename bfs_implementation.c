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
    if (ptr->back==ptr->size-1){
        return 1;
    }
    return 0;
}
int enqueue(struct Queue *q,int value){
    if (isFull(q)){
        printf("Queue overflow\n");
    }
    else{
        q->back++;
        q->arr[q->back]=value;
    }
}
int dequeue(struct Queue *q){
    int a=-1;
    if (isEmpty(q)){
        printf("Queue underflow\n");
    }
    else{
        q->front++;
        a=q->arr[q->front];
        for (int i = q->front + 1; i <= q->back; i++) {
            q->arr[i - 1] = q->arr[i];
        }
        q->back--;
        q->front--;
    }
    return a;
}
int main(){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size=50;
    q->back=-1;
    q->front=-1;
    q->arr=(int *)malloc(q->size*sizeof(int));

    // BFS implementation
    int node;
    int i=4; // source node 
    int visited[7]={0,0,0,0,0,0,0};
    /*
           0_____1
           | \   | 
           |   \ |
           2_____3
            \   /
              4
            /   \
           5     6
    */
   // adjacency matrix
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    printf("%d ",i);
    visited[i]=1;
    enqueue(q,i); //Enqueue i for exploration
    while (!isEmpty(q)){
        int node = dequeue(q);
        for (int j=0; j<7; j++){
            if (a[node][j]==1 && visited[j]==0){
                printf(" %d ",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }
    return 0;
}