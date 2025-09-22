#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int *arr;
};

void TraversalArr(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("Element: %d\n",s->arr[i]);
        }
    }
}

void push(struct Stack *s, int element) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = element;
    }
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1; // sentinel value
    } else {
        int element = s->arr[s->top];
        s->top--;
        return element;
    }
}

int main() {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->size = 10;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 48);
    push(s, 88);
    push(s, 97);
    push(s, 123);
    push(s, 73);

    TraversalArr(s);
    printf("------------------------------\n");
    pop(s);
    TraversalArr(s);

    // free(s->arr);
    // free(s);

    return 0;
}
