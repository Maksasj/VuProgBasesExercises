#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int size;
} Stack;

void initStack(Stack *stack) {
    stack->size = 0;
}

void printStack(Stack* stack) {
    for(int i = 0; i < stack->size; ++i)
        printf("%d ", *(stack->data + i));
}

int getStackSize(Stack *stack) {
    return stack->size;
}

void push(Stack* stack, int value) {
    stack->data = realloc(stack->data, (++stack->size) * sizeof(int));
    *(stack->data + stack->size - 1) = value;
}

int top(Stack *stack) {
    if(stack->size == 0) return 0;

    return stack->data[stack->size - 1];
}

int pop(Stack *stack) {
    if(stack->size == 0) return 0;

    int value = *(stack->data + (--stack->size));

    stack->data = realloc(stack->data, stack->size * sizeof(int));

    return value;
}

void destroyStack(Stack *stack) {
    free(stack->data);
    stack->size = 0;
}

int main() {
    Stack stack;

    initStack(&stack);
 
    push(&stack, 5);
    push(&stack, 2);
    push(&stack, 1);
    push(&stack, 3);
    push(&stack, 4);

    printStack(&stack);

    int v = pop(&stack);

    printf("\n");
    printStack(&stack);

    return 0;
}