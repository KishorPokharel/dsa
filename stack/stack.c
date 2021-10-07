#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* new_stack() {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = -1;
    return st;
}

int is_stack_empty(Stack* st) {
    if (st->top == -1) {
        return 1;
    }
    return 0;
}

int is_stack_full(Stack* st) {
    if (st->top == MAX - 1) {
        return 1;
    }
    return 0;
}

void push(Stack* st, int data) {
    if(is_stack_full(st)) {
        fprintf(stderr, "[!] cannot push to full stack");
        return;
    }
    st->items[st->top+1] = data;
    st->top = st->top + 1;
}

void pop(Stack* st, int* out) {
    if(is_stack_empty(st)) {
        fprintf(stderr, "[!] cannot pop from empty stack");
        return;
    }
    *out = st->items[st->top];
    st->top = st->top - 1;
}

void peek(Stack* st, int* out) {
    if(is_stack_empty(st)) {
        return;
    }
    *out = st->items[st->top];
}

void print_stack(Stack* st) {
    int len = st->top;
    int i = 0;
    while(!(i > len)) {
        printf("%d ", st->items[i]);
        i++;
    }
    printf("\n");
}

int main() {
    Stack* st = new_stack();
    printf("Is stack full? %d\n", is_stack_full(st));
    printf("Is stack empty? %d\n", is_stack_empty(st));

    push(st, 4);
    push(st, 5);
    push(st, 6);
    print_stack(st);
    int out;
    pop(st, &out);
    print_stack(st);

    printf("Out: %d", out);
    free(st);
    return 0;
}
