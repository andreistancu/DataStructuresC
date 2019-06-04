#ifndef STACK_H
#define STACK_H

#include "node.h"

#define MAX_STACK_SIZE	10

typedef struct stack
{
	struct node *top;
	size_t size;
	size_t capacity;
	size_t elemSize;
} Stack;

Stack *initStack(size_t);
int isStackEmpty(Stack *);
int isStackFull(Stack *);
void push(Stack *, void *);
void *pop(Stack *);
Node *top(Stack *);
void printStack(Stack *);
void printClearStack(Stack *);
void freeStack(Stack **);

#endif