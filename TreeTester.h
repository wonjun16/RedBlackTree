#pragma once

#include <vector>
#include "TreeTemplate.h"

/*
int 전용 tester입니다. 
유동적인 타입을 위한 tester를 만드려면 template class로 만들어야 합니다.
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

