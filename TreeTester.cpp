#include "TreeTester.h"
#include <algorithm>
#include <stdio.h>
#include <random>
#include <time.h>

TreeTester::TreeTester(Tree<int>* t)
{
	tree = t;
	idx = 0;
}

TreeTester::~TreeTester()
{
	delete tree;
}

bool TreeTester::InsertData(int data)
{
	bool success = tree->Insert(data);
	if (!success) return false;

	TreeData.push_back(data);
	std::sort(TreeData.begin(), TreeData.end());

	return true;
}

bool TreeTester::DeleteData(int data)
{
	bool success = tree->Delete(data);
	if (!success) return false;

	for (auto it = TreeData.begin(); it != TreeData.end();)
	{
		if (data == *it)
		{
			it = TreeData.erase(it);
		}
		else ++it;
	}

	return true;
}

void TreeTester::Run()
{
	srand(time(NULL));

	int index = 1;
	int maxIndex = 10000;

	while (index <= maxIndex)
	{
		int op = rand() % 2 + 1;
		int randData = rand() % 10000 + 1;

		printf("--------------------------- %d ---------------------------\n", index);

		if (op == 1)
		{
			bool sc = InsertData(randData);
			if (sc == false) printf("InsertData Fail. Data : %d\n", randData);
			else printf("InsertData Success. Data : %d\n", randData);
		}
		else if (op == 2)
		{
			bool sc = DeleteData(randData);
			if (sc == false) printf("DeleteData Fail. Data : %d\n", randData);
			else printf("DeleteData Success. Data : %d\n", randData);
		}

		//Check if tree is valid
		idx = 0;
		bool sc = CheckTree(tree->GetRoot());
		if (sc)
		{
			printf("\nSUCCESS\n");
		}
		else
		{
			printf("\nFAILED\n");
			break;
		}

		index++;
	}
}

bool TreeTester::CheckTree(Tree<int>::Node* node)
{
	if (node == nullptr || node == tree->GetNil()) return true;

	bool result = true;

	if (!CheckTree(node->LeftChild)) result = false;

	if (TreeData[idx] != node->Data)
	{
		printf("OPERATION FAILED. IDX : %d / Data : %d\n", idx, node->Data);
		result = false;
	}
	else
	{
		printf("IDX : %d / Data : %d ",idx, node->Data);
	}
	
	idx++;

	if (!CheckTree(node->RightChild)) result = false;

	return result;
}