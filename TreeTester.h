#pragma once

#include <vector>
#include "TreeTemplate.h"

/*
int ���� tester�Դϴ�. 
�������� Ÿ���� ���� tester�� ������� template class�� ������ �մϴ�.
*/

class TreeTester
{
public:
	TreeTester(Tree<int>* t);
	~TreeTester();

	bool InsertData(int data);
	bool DeleteData(int data);

	void Run();

	bool CheckTree(Tree<int>::Node* node); 
private:
	std::vector<int>TreeData;
	Tree<int>* tree;
	int idx;
};

