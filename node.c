#include <stdlib.h>
#include <string.h>
#include "node.h"

Node *initNode(void *data, size_t size)
{
	Node *newNode = NULL;

	newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	
	newNode->next = NULL;
	newNode->data = malloc(size);
	if (newNode->data == NULL)
	{
		free(newNode);
		return NULL;
	}
	memset(newNode->data, 0, size);
	memcpy(newNode->data, data, size);

	return newNode;
}

void printNode(Node *node)
{
	int *val = (int *) node->data;
	printf("%d->", *val);
}