#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

#define MAX_QUEUE_SIZE	10

typedef struct queue
{
	struct node *front;
	struct node *rear;
	size_t size;
	size_t capacity;
	size_t elemSize;
} Queue;

Queue *initQueue(size_t);
int isQempty(Queue *);
int isQfull(Queue *);
void enqueue(Queue *, void *);
void *dequeue(Queue *);
Node *peek(Queue *);
void printQueue(Queue *);
void printClearQueue(Queue *);
void freeQueue(Queue **);

#endif