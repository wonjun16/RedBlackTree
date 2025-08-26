#include "BinaryTree.h"
#include "TreeTester.h"
#include "RedBlackTree.h"

int main()
{
	//BinaryTree tree;
	RedBlackTree tree;
	TreeTester* tester = new TreeTester(&tree);
	tester->Run();

	return 0;
}