#include "BinaryTree.h"
#include "TreeTester.h"

int main()
{
	BinaryTree tree;
	TreeTester* tester = new TreeTester(&tree);
	tester->Run();
	return 0;
}