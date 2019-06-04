#ifndef SLIST_H
#define SLIST_H

#include "node.h"

#define MAX_LIST_SIZE	10

typedef struct slist
{
	struct node *head;
	size_t size;
	size_t elemSize;
	size_t capacity;
	int (*cmpFunction)(const void *, const void *);
} List;

List *initList(size_t, int (*cmpFunction)(const void *, const void *));
int isListEmpty(List *);
int isListFull(List *);
void addFirst(List *, void *);
void addLast(List *, void *);
void* removeFirst(List *);
void* removeLast(List *);
void* removeValue(List *, void *);
Node *searchNode(List *, void *);
unsigned int getSize(List *);
void printList(List *);
void freeNodes(List *);
void freeList(List **);

#endif