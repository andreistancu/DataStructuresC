#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
#include "queue.h"
#include "node.h"

TNode *initTNode(void *data, size_t size)
{
	TNode *newNode = NULL;

	newNode = malloc(sizeof(TNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->data = malloc(size);
	if (newNode->data == NULL)
	{
		free(newNode);
		return NULL;
	}
	memcpy(newNode->data, data, size);
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

BSTree *initTree(size_t elemSize, int (*cmpFunction)(const void *, const void *))
{
	BSTree *tree = malloc(sizeof(BSTree));
	tree->root = NULL;
	tree->elemSize = elemSize;
	tree->cmpFunction = cmpFunction;
}

void insertNode(BSTree *tree, void *data)
{
	TNode *root = tree->root;
	TNode *parent = NULL;
	TNode *newNode = initTNode(data, tree->elemSize);
	while (root != NULL)
	{
		parent = root;
		if (tree->cmpFunction(data, root->data) < 0)
		{
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}
	if (parent == NULL)
	{
		tree->root = newNode;
	}
	else if (tree->cmpFunction(data, parent->data) < 0)
	{
		parent->left = newNode;
	}
	else
	{
		parent->right = newNode;
	}
}

TNode *search(BSTree *tree, void *data)
{
	TNode *root = tree->root;
	TNode *parent = NULL;

	while (root != NULL)
	{
		if (tree->cmpFunction(data, root->data) == 0)
		{
			return root;
		}
		else if (tree->cmpFunction(data, root->data) < 0)
		{
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}
	return NULL;
}

void printTNode(TNode *node)
{
	int *val = (int *) node->data;
	printf("%d, ", *val);
}

void inorder(TNode *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	printTNode(root);
	inorder(root->right);
}

void preorder(TNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printTNode(root);
	inorder(root->left);
	inorder(root->right);
}

void postorder(TNode *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	inorder(root->right);
	printTNode(root);
}

void BFSTraversal(BSTree *tree)
{
	TNode *temp = tree->root;
	Queue *q;

	if (temp == NULL)
	{
		return;
	}

	q = initQueue(sizeof(TNode));
	enqueue(q, temp);

	while (!isQempty(q))
	{
		temp = dequeue(q);
		printTNode(temp);
		if (temp->left != NULL)
		{
			enqueue(q, temp->left);
		}
		if (temp->right != NULL)
		{
			enqueue(q, temp->right);
		}
	}
	printf("\n");
}

// void insertNode(TNode **root, void *data, int (*cmpFunction)(void *, void *))
// {
// 	if (*root == NULL)
// 	{
// 		*root = initTNode(data);
// 	}
// 	else if (cmpFunction(data, (*root)->data) < 0)
// 	{
// 		if ((*root)->left == NULL)
// 		{
// 			(*root)->left = initTNode(data);
// 		}
// 		else
// 		{
// 			insertNode(&(*root)->left, data, cmpFunction);
// 		}
// 	}
// 	else
// 	{
// 		if ((*root)->right == NULL)
// 		{
// 			(*root)->right = initTNode(data);
// 		}
// 		else
// 		{
// 			insertNode(&(*root)->right, data, cmpFunction);
// 		}
// 	}
// }

// TNode *search(TNode *root, void *data, int (*cmpFunction)(void *, void *))
// {
// 	if (root == NULL || cmpFunction(data, root->data) == 0)
// 	{
// 		return root;
// 	}
// 	else if (cmpFunction(data, root->data) < 0)
// 	{
// 		return search(root->left, data, cmpFunction);
// 	}
// 	else
// 	{
// 		return search(root->right, data, cmpFunction);
// 	}
// }
