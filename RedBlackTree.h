#pragma once

#include "TreeTemplate.h"

class RedBlackTree : public Tree<int>
{
public:
	RedBlackTree();
	~RedBlackTree() override;

	bool Insert(int data) override;
	bool Delete(int target) override;

private:
	void RotateLeft(Node* node);
	void RotateRight(Node* node);
};