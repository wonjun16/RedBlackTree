#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
	Nil = new Node();
	Nil->Color = BLACK;
	Nil->LeftChild = nullptr;
	Nil->RightChild = nullptr;
	Nil->Parent = nullptr;
}

RedBlackTree::~RedBlackTree()
{
	delete Nil;
}

bool RedBlackTree::Insert(int data)
{
	if (Root == nullptr)
	{
		Node* node = new Node();
		node->Color = BLACK;
		node->Data = data;
		node->LeftChild = Nil;
		node->RightChild = Nil;
		node->Parent = nullptr;

		Root = node;
		return true;
	}

	Node* cur = Root;
	Node* parent = cur->Parent;

	while (cur != Nil)
	{
		parent = cur;
		if (cur->Data == data) return false;
		else if (cur->Data > data) cur = cur->LeftChild;
		else if (cur->Data < data) cur = cur->RightChild;
	}
	
	Node* node = new Node();
	node->Color = RED;
	node->Data = data;
	node->LeftChild = Nil;
	node->RightChild = Nil;
	node->Parent = parent;

	if (parent->Data < data) parent->RightChild = node;
	else parent->LeftChild = node;

	//re balancing


	return true;
}

bool RedBlackTree::Delete(int target)
{
	return false;
}

void RedBlackTree::TurnLeft(Node* node)
{
}

void RedBlackTree::TurnRight(Node* node)
{
	Node* parent = node->Parent;
	Node* grand = parent->Parent;
	Node* uncle = grand->RightChild;
	Node* sibling = parent->RightChild;

	if (grand->Parent)
	{
		if (grand->Parent->Data < grand->Data)grand->Parent->RightChild = parent;
		else grand->Parent->LeftChild = parent;
	}
	parent->Parent = grand->Parent;



}
