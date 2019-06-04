#include <stdio.h>
#include "node.h"
#include "slist.h"
#include "queue.h"
#include "stack.h"
#include "bstree.h"
#include "graph.h"

int main()
{
	int v[100];
	int i;
	int n = 10;
	int m = 12;
	int x = 50;
	void *elem;

	Graph *g = initGraph(4, sizeof(int));
	int nodes[100] = {25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};

	for (i = 0; i < 15; i++)
	{
		// insertNode(tree, &nodes[i]);
		
	}
	// elem = pop(st);
	// printf("%d\n", *(int *) elem);
	// printStack(st);
	
	// printClearStack(st);

	// addEdge(g, 0, 1); 
 //    addEdge(g, 0, 4); 
 //    addEdge(g, 1, 2); 
 //    addEdge(g, 1, 3); 
 //    addEdge(g, 1, 4); 
 //    addEdge(g, 2, 3); 
 //    addEdge(g, 3, 4);

	addEdge(g, 0, 1); 
    addEdge(g, 0, 2); 
    addEdge(g, 1, 2); 
    // addEdge(g, 2, 0); 
    addEdge(g, 2, 3); 
    addEdge(g, 3, 3); 

    printGraph(g);
    // DFS(g, 2);
    BFS(g, 2);
}
