#ifndef GRAPH_H
#define GRAPH_H

#include "slist.h"

// #define DIRECTED_GRAPH		1
// #define GRAPH_ADJ_MATRIX		1

#ifndef GRAPH_ADJ_MATRIX

typedef struct graph
{
	unsigned int nodes;
	struct slist **adjList;
	size_t elemSize;
	int *visited;
} Graph;

#else

typedef struct graph
{
	unsigned int nodes;
	int **adj_matrix;
} Graph;

#endif

Graph *initGraph(unsigned int v, size_t elemSize);
void addEdge(Graph *, unsigned int, unsigned int);
int isEdge(Graph *, unsigned int, unsigned int);
void deleteEdge(Graph *, unsigned int, unsigned int);
List *getAdjList(Graph *, unsigned int);
void addNode(Graph *, unsigned int);
void delNode(Graph *, unsigned int);
void printGraph(Graph *);
void DFS(Graph *, unsigned int);
void BFS(Graph *, unsigned int);

#endif