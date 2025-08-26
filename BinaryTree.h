#pragma once

#include "TreeTemplate.h"

class BinaryTree : public Tree<int>
{
public:
	BinaryTree();
	~BinaryTree() override;

	bool Insert(int data) override;
	bool Delete(int target) override;
	void ShowTree(Node*);
	void Clear(Node*);
};