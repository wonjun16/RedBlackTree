#include "BinaryTree.h"

int main()
{
	BinaryTree tree;

	tree.Insert(5);
	tree.Insert(3);

	tree.Delete(4);
	tree.Delete(5);

	tree.Insert(50);
	tree.Insert(10);
	tree.Insert(7);

	tree.Delete(10);
	//tree.Delete(50);

	tree.ShowTree(tree.root);

	return 0;
}