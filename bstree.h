#ifndef BSTREE_H
#define BSTREE_H

typedef struct tnode
{
	struct tnode *left;
	struct tnode *right;
	void *data;
} TNode;

typedef struct bstree
{
	TNode *root;
	size_t elemSize;
	int (*cmpFunction)(const void *, const void *);
} BSTree;

TNode *initTNode(void *data, size_t size);
BSTree *initTree(size_t, int (*cmpFunction)(const void *, const void *));
void insertNode(BSTree *tree, void *data);
TNode *search(BSTree *tree, void *data);
void printTNode(TNode *node);
void inorder(TNode *root);
void preorder(TNode *root);
void postorder(TNode *root);
void BFSTraversal(BSTree *tree);

#endif