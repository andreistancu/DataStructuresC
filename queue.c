#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *initQueue(size_t elemSize)
{
	Queue *q = malloc(sizeof(Queue));

	if (q == NULL)
	{
		return NULL;
	}
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	q->capacity = MAX_QUEUE_SIZE;
	q->elemSize = elemSize;

	return q;
}

int isQempty(Queue *q)
{
	return (q->rear == NULL);
}

int isQfull(Queue *q)
{
	return (q->size == q->capacity);
}

void enqueue(Queue *q, void *data)
{
	Node *new_node = NULL;

	if (isQfull(q))
	{
		printf("Queue is full!\n");
		return;
	}

	new_node = initNode(data, q->elemSize);
	if (isQempty(q))
	{
		q->front = new_node;
		q->rear = new_node;
	}
	else
	{
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->size++;
}

void *dequeue(Queue *q)
{
	Node *first = NULL;
	void *elem = NULL;

	if (isQempty(q))
	{
		printf("Queue is empty!\n");
		return NULL;
	}

	first = q->front;
	elem = first->data;
	q->front = first->next;
	free(first);
	q->size--;
	if (q->front == NULL)
	{
		q->rear = NULL;
	}

	return elem;
}

Node *peek(Queue *q)
{
	if (isQempty(q))
	{
		printf("Queue is empty!\n");
		return NULL;
	}
	return q->front;
}

void printQueue(Queue *q)
{
	Node *temp = q->front;

	while (temp != NULL)
	{
		printNode(temp);
		temp = temp->next;
	}
	printf("\n");
}

void printClearQueue(Queue *q)
{
	void *elem = NULL;
	Node *temp = NULL;

	while (!isQempty(q))
	{
		printNode(q->front);
		temp = dequeue(q);
		free(temp);
	}
	q->front = NULL;
	q->rear = NULL;
	printf("\n");
}

void freeQueue(Queue **q)
{
	Queue *auxq = *q;
	void *elem;

	while (!isQempty(auxq))
	{
		elem = dequeue(auxq);
		free(elem);
	}
	free(*q);
	*q = NULL;
}