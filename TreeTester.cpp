#include "TreeTester.h"
#include <algorithm>
#include <stdio.h>
#include <random>
#include <time.h>

TreeTester::TreeTester(Tree<int>* t, TreeType treetype)
{
	tree = t;
	idx = 0;
	type = treetype;
	blackCnt = 0;
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
	int maxIndex = 1000;

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

		//Check if tree is correctly sorted
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

		//Check Black count / Red - Red issue
		if (type == RedBlack)
		{
			blackCnt = 0;
			Tree<int>::Node* temp = tree->GetRoot();
			while (temp)
			{
				if (temp->Color == BLACK) blackCnt++;
				temp = temp->LeftChild;
			}

			bool result;
			result = CheckBlackCount(tree->GetRoot(), 0);
			if (result) printf("BLACK COUNT SUCCESS\n");
			else
			{
				printf("BLACK COUNT FAIL\n");
				//__debugbreak();
			}

			result = CheckRedRed(tree->GetRoot(), 1);
			if (result) printf("RED RED SUCCESS\n");
			else
			{
				printf("RED RED FAIL\n");
				__debugbreak();
			}
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
		//printf("IDX : %d / Data : %d ",idx, node->Data);
		printf("%d ", node->Data);
	}
	
	idx++;

	if (!CheckTree(node->RightChild)) result = false;

	return result;
}

bool TreeTester::CheckBlackCount(Tree<int>::Node* node, int cnt)
{
	if (node == nullptr)
	{
		if (cnt != blackCnt)
		{
			printf("Black count : %d / Cur Count : %d\n", blackCnt, cnt);
			return false;
		}
		return true;
	}

	bool result = true;

	if (node->Color == BLACK)
	{
		if(result) result = CheckBlackCount(node->LeftChild, cnt + 1);
		if(result) result = CheckBlackCount(node->RightChild, cnt + 1);
	}
	else
	{
		if(result) result = CheckBlackCount(node->LeftChild, cnt);
		if(result) result = CheckBlackCount(node->RightChild, cnt);
	}

	return result;
}

bool TreeTester::CheckRedRed(Tree<int>::Node* node, bool flag)
{
	if (node == nullptr) return true;

	if (flag == 0 && node->Color == RED)return false;

	bool result = true;

	if (node->Color == BLACK)
	{
		if (result) result = CheckRedRed(node->LeftChild, 1);
		if (result) result = CheckRedRed(node->RightChild, 1);
	}
	else
	{
		if (result) result = CheckRedRed(node->LeftChild, 0);
		if (result) result = CheckRedRed(node->RightChild, 0);
	}

	return result;
}
