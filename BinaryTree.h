#pragma once

struct Node
{
	int Data;
	Node* LeftChild;
	Node* RightChild;
	Node* Parent;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	bool Insert(int data);
	bool Delete(int target);
	void ShowTree(Node*);

	Node* root;
private:
	
};