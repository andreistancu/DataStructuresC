#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "queue.h"
#include "utils.h"

Graph *initGraph(unsigned int v, size_t elemSize)
{
	int i;
	Graph *g = malloc(sizeof(Graph));
	if (g == NULL)
	{
		return NULL;
	}
	g->nodes = v;
	g->elemSize = elemSize;
	g->visited = calloc(v, sizeof(int));
	if (g->visited == NULL)
	{
		free(g);
		return NULL;
	}
	g->adjList = calloc(v, sizeof(List *));
	if (g->adjList == NULL)
	{
		free(g);
		return NULL;
	}
	for (i = 0; i < v; i++)
	{
		g->adjList[i] = initList(sizeof(Node), &compareInts);
		if (g->adjList[i] == NULL)
		{
			free(g->adjList);
			free(g);
		}
	}
	return g;
}

void addEdge(Graph *g, unsigned int src, unsigned int dest)
{
	addLast(g->adjList[src], &dest);
#ifndef DIRECTED_GRAPH
	addLast(g->adjList[dest], &src);
#endif
}

int isEdge(Graph *g, unsigned int src, unsigned int dest)
{
	if (searchNode(g->adjList[src], &dest))
	{
		return 1;
	}
	return 0;
}

void deleteEdge(Graph *g, unsigned int src, unsigned int dest)
{
	removeValue(g->adjList[src], &dest);
#ifndef DIRECTED_GRAPH
	removeValue(g->adjList[dest], &src);
#endif
}

List *getAdjList(Graph *g, unsigned int id)
{
	return g->adjList[id];
}

void printGraph(Graph *g)
{
	int v;
	for (v = 0; v < g->nodes; v++)
	{
		printf("Adjacency list of vertex [%d] is ", v); 
		printList(g->adjList[v]);
	}
}

void DFS(Graph *g, unsigned int start)
{
	printf("%d->", start);
	g->visited[start] = 1;
	Node *head = g->adjList[start]->head;
	while (head != NULL)
	{
		int node_val = *(int *) head->data;
		if (g->visited[node_val] == 0)
		{
			DFS(g, node_val);
		}
		head = head->next;
	}
}

void BFS(Graph *g, unsigned int start)
{
	Queue *q = NULL;
	void * elem = NULL;
	Node *head = NULL;
	int node_val;

	memset(g->visited, 0, g->elemSize);
	q = initQueue(g->elemSize);
	head = g->adjList[start]->head;
	enqueue(q, &start);
	g->visited[start] = 1;

	while (!isQempty(q))
	{
		elem = dequeue(q);
		node_val = *(int *) elem;
		g->visited[node_val] = 1;
		printf("%d->", node_val);
		while (head != NULL)
		{
			node_val = *(int *) head->data;
			if (g->visited[node_val] == 0)
			{
				enqueue(q, &node_val);
			}
			head = head->next;
		}
	}
}
