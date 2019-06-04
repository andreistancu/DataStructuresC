#ifndef NODE_H
#define NODE_H

#include <stdio.h>

typedef struct node
{
	void *data;
	struct node *next;
} Node;

Node *initNode(void *, size_t);
void printNode(Node *);

#endif