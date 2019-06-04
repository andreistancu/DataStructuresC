#include <stdlib.h>

#include "stack.h"

Stack *initStack(size_t elemSize)
{
	Stack *st = malloc(sizeof(Stack));

	if (st == NULL)
	{
		return NULL;
	}
	st->top = NULL;
	st->size = 0;
	st->capacity = MAX_STACK_SIZE;
	st->elemSize = elemSize;

	return st;
}

int isStackEmpty(Stack *st)
{
	return (st->top == NULL);
}

int isStackFull(Stack *st)
{
	return (st->size == st->capacity);
}

void push(Stack *st, void *data)
{
	Node *newNode = NULL;

	if (isStackFull(st))
	{
		printf("Stack overflow!\n");
		return;
	}
	newNode = initNode(data, st->elemSize);
	newNode->next = st->top;
	st->top = newNode;
	st->size++;
}

void *pop(Stack *st)
{
	Node *top = NULL;
	void *elem = NULL;

	if (isStackEmpty(st))
	{
		printf("Stack underflow!\n");
		return NULL;
	}
	top = st->top;
	st->top = top->next;
	elem = top->data;
	free(top);
	st->size--;

	return elem;
}

Node *top(Stack *st)
{
	if (isStackEmpty(st))
	{
		printf("Stack underflow!\n");
		return NULL;
	}
	return st->top;
}

void printStack(Stack *st)
{
	Node *top = st->top;
	while (top != NULL)
	{
		printNode(top);
		top = top->next;
	}
	printf("\n");
}

void printClearStack(Stack *st)
{
	Node *top = NULL;
	void *elem = NULL;

	while (!isStackEmpty(st))
	{
		printNode(st->top);
		top = pop(st);
		free(top);
	}
	st->top = NULL;
	printf("\n");
}

void freeStack(Stack **st)
{
	Stack *auxst = *st;
	void *elem = NULL;

	while (!isStackEmpty(auxst))
	{
		elem = pop(auxst);
		free(elem);
	}
	free(*st);
	*st = NULL;
}