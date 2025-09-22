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
int isFull(struct Stack *ptr){
    if (ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}
int push(struct Stack *s,int value){
    if (isFull(s)){
        printf("Stack overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=value;
    }
}
int pop(struct Stack *s){
    if (isEmpty(s)){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        int value=s->arr[s->top];
        s->top--;
        return value;
    }
}
int peek(struct Stack *s, int i){
    if (s->top - i + 1 < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return s->arr[s->top - i + 1];
    }
}
int stackBottom(struct Stack *s){
    return s->arr[0];
}
int stackTop(struct Stack *s){
    return s->arr[s->top];
}
int main(){
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
                //position    index
    push(s,41); //5           0
    push(s,54); //4           1
    push(s,36); //3           2
    push(s,78); //2           3
    push(s,53); //1           4

    printf("%d\n",stackBottom(s));
    printf("%d\n",stackTop(s));
    return 0;
}
