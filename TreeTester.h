#pragma once

#include <vector>
#include "TreeTemplate.h"

enum TreeType
{
	Binary=0,
	RedBlack
};

/*
int ���� tester�Դϴ�. 
�������� Ÿ���� ���� tester�� ������� template class�� ������ �մϴ�.
*/

class TreeTester
{
public:
	TreeTester(Tree<int>* t, TreeType);
	~TreeTester();

	bool InsertData(int data);
	bool DeleteData(int data);

	void Run();

	bool CheckTree(Tree<int>::Node* node); 
	bool CheckBlackCount(Tree<int>::Node* node, int cnt);
	bool CheckRedRed(Tree<int>::Node* node, bool flag);
private:
	std::vector<int>TreeData;
	Tree<int>* tree;
	int idx;
	int blackCnt;
	TreeType type;
};

