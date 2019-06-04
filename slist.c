#include <stdlib.h>
#include "slist.h"

List *initList(size_t elemSize, int (*cmpFunction)(const void *, const void *))
{
	List *list = malloc(sizeof(List));
	if (list == NULL)
	{
		return NULL;
	}
	list->head = NULL;
	list->size = 0;
	list->capacity = MAX_LIST_SIZE;
	list->elemSize = elemSize;
	list->cmpFunction = cmpFunction;
	return list;
}

int isListEmpty(List *list)
{
	return (list->head == NULL);
}

int isListFull(List *list)
{
	return (list->size == list->capacity);
}

void addFirst(List *list, void *data)
{
	Node *temp;

	if (isListFull(list))
	{
		printf("List is full!\n");
		return;
	}
	temp = initNode(data, list->elemSize);
	temp->next = list->head;
	list->head = temp;
	list->size++;
}

void addLast(List *list, void *data)
{
	Node *temp = list->head;
	Node *last = NULL;

	if (isListFull(list))
	{
		printf("List is full!\n");
		return;
	}
	if (isListEmpty(list))
	{
		addFirst(list, data);
		return;
	}
	while (temp != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = initNode(data, list->elemSize);
	list->size++;
}

void *removeFirst(List *list)
{
	Node *first = NULL;
	void *elem = NULL;
	if (isListEmpty(list))
	{
		printf("List is empty!\n");
		return NULL;
	}
	first = list->head;
	elem = first->data;
	list->head = first->next;
	free(first->data);
	free(first);
	list->size--;
	return elem;
}

void *removeLast(List *list)
{
	Node *head = NULL;
	Node *prev = NULL;
	void *elem = NULL;

	if (isListEmpty(list))
	{
		printf("List is empty!\n");
		return NULL;
	}
	head = list->head;
	if (head->next == NULL)
	{
		return removeFirst(list);
	}

	while (head->next != NULL)
	{
		prev = head;
		head = head->next;
	}
	elem = head->data;
	free(prev->next->data);
	free(prev->next);
	list->size--;
	prev->next = NULL;
	return elem;
}

void* removeValue(List *list, void *data)
{
	Node *head = NULL;
	Node *prev = NULL;
	void *elem = NULL;

	if (isListEmpty(list))
	{
		printf("List is empty!\n");
		return NULL;
	}

	if (list->cmpFunction(list->head, data) == 0)
	{
		return removeFirst(list);
	}

	head = list->head;
	while (head != NULL)
	{
		if (list->cmpFunction(list->head, data) == 0)
		{
			elem = head->data;
			prev->next = head->next;
			free(head);
			list->size--;
			return elem;
		}
		prev = head;
		head = head->next;
	}
	return NULL;
}

Node *searchNode(List *list, void *data)
{
	Node *head = NULL;
	if (isListEmpty(list))
	{
		return NULL;
	}

	head = list->head;
	while (head != NULL)
	{
		if (list->cmpFunction(data, head->data) == 0)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

unsigned int getSize(List *list)
{
	return list->size;
}

void printList(List *list)
{
	Node *head = list->head;
	while (head != NULL)
	{
		printNode(head);
		head = head->next;
	}
	printf("\n");
}

void freeNodes(List *list)
{
	List *laux = list;
	Node *temp = laux->head;
	Node *prev = NULL;

	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev->data);
		free(prev);
	}
	list->head = NULL;
	list->size = 0;
}

void freeList(List **list)
{
	List *laux = *list;
	Node *temp = laux->head;
	Node *prev = NULL;

	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev->data);
		free(prev);
	}
	free(*list);
	*list = NULL;
}