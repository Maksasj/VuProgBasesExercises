#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} Point;

Point createPoint(double x, double y) {
    return (Point){ x, y };
}

double getDistance(Point a, Point b) {
    return sqrt( (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y) );
}

void printPoint(Point p) {
    printf("(%f, %f)", p.x, p.y);
}

typedef struct Stack {
    Point *data;
    int size;
} Stack;

void initStack(Stack *stack) {
    stack->size = 0;
}

void printStack(Stack* stack) {
    for(int i = 0; i < stack->size; ++i) {
        printf("\nDistance from (0, 0) to ");
        printPoint(stack->data[i]);
        printf(" is %f", getDistance(createPoint(0.0, 0.0), stack->data[i]));
    }
}

int getStackSize(Stack *stack) {
    return stack->size;
}

void push(Stack* stack, Point value) {
    if(stack->size == 0) {
        stack->data = malloc(2 * sizeof(double));
        stack->data[0] = value;
        ++stack->size;
        return;
    }

    stack->data = realloc(stack->data, (++stack->size) * 2 * sizeof(double));
    stack->data[stack->size - 1] = value;
}

Point top(Stack *stack) {
    if(stack->size == 0) return createPoint(0.0, 0.0);

    return stack->data[stack->size - 1];
}

Point pop(Stack *stack) {
    if(stack->size == 0) return createPoint(0.0, 0.0);

    Point value = *(stack->data + (--stack->size));

    stack->data = realloc(stack->data, stack->size * sizeof(Point));

    return value;
}

void destroyStack(Stack *stack) {
    free(stack->data);
    stack->size = 0;
}

Point get(Stack *stack, int index) {
    return stack->data[index];
}

int main() {
    Stack stack;

    initStack(&stack);

    push(&stack, createPoint(-1.0, -6.4));
    push(&stack, createPoint(0.12, 9.9));
    push(&stack, createPoint(3.0, -4.4));
    push(&stack, createPoint(-0.59, 8.9));
    push(&stack, createPoint(-2.1, -1.2));

    printStack(&stack);

    destroyStack(&stack);

    return 0;
}