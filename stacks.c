# include <stdio.h>
# include <stdlib.h>

struct Stack{
    int top;
    int size;
    int *arr;
};
int isEmpty(struct Stack *ptr){
    if (ptr->top==-1){
        return 1;
    }
    return 0;
}
// (*ptr).top
int isFull(struct Stack *ptr){
    if (ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}
void push(struct Stack *s,int value){
    if (isFull(s)){
        printf("Stack overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=value;
    }
}

int main(){
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));

    // repetetive approach
    // s->arr[0]=45;
    // s->top++;
    // s->arr[1]=35;
    // s->top++;
    // s->arr[2]=54;
    // s->top++;
    // s->arr[3]=89;
    // s->top++;
    // s->arr[4]=96;
    // s->top++;
    // s->arr[5]=69;
    // s->top++;
    // s->arr[6]=23;
    // s->top++;
    // s->arr[7]=78;
    // s->top++;

    
    push(s,41);
    if (isFull(s)){
        printf("Stack is full\n");
    }
    else{
        printf("Stack still got some space\n");
    }
    return 0;
}
