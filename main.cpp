#include "BinaryTree.h"
#include "TreeTester.h"
#include "RedBlackTree.h"

int main()
{
	//BinaryTree tree;
	RedBlackTree tree;
	TreeTester* tester = new TreeTester(&tree, TreeType::RedBlack);
	tester->Run();

	return 0;
}