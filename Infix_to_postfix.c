#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedences(char c){
    int prec;
    if (c=='*' || c=='/'){
        prec=1;
    }
    else if(c=='+' || c=='-'){
        prec=2;
    }
    return prec;
}

void infix_to_postfix(char *infix_exp){
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *posfix_exp=(char *)malloc(sp->size*sizeof(char));
    int i=0;
    do{
        push(sp,infix_exp[i]);
        i++;
    }while (!isEmpty(sp) && precedences(sp->arr[sp->top]>=precedences(infix_exp[i])));
    char popped_chr=pop(sp);
    strcat(posfix_exp,popped_chr);
    printf(posfix_exp);
}
int main()
{
    char * exp = "a+b/-c+d*e";
    infix_to_postfix(exp);
    return 0;
}
