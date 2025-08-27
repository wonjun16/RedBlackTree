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
	while (parent && parent->Color == RED)
	{
		Node* grand = parent->Parent;
		Node* uncle;

		if (grand->LeftChild == parent)
		{
			uncle = grand->RightChild;

			if (parent->Color == RED && uncle->Color == RED)
			{
				parent->Color = BLACK;
				uncle->Color = BLACK;
				grand->Color = RED;
				node = grand;
			}
			else if (parent->RightChild == node)
			{
				RotateLeft(parent);
				node = parent;
			}
			else if (parent->Color == RED && uncle->Color == BLACK)
			{
				parent->Color = BLACK;
				grand->Color = RED;
				RotateRight(grand);
				node = parent;
			}
		}
		else
		{
			uncle = grand->LeftChild;

			if (parent->Color == RED && uncle->Color == RED)
			{
				parent->Color = BLACK;
				uncle->Color = BLACK;
				grand->Color = RED;
				node = grand;
			}
			else if (parent->LeftChild == node)
			{
				RotateRight(parent);
				node = parent;
			}
			else if (parent->Color == RED && uncle->Color == BLACK)
			{
				parent->Color = BLACK;
				grand->Color = RED;
				RotateLeft(grand);
				node = parent;
			}
		}
		parent = node->Parent;
	}

	Root->Color = BLACK;
	return true;
}

bool RedBlackTree::Delete(int target)
{
	return false;
}

void RedBlackTree::RotateLeft(Node* node)
{
	Node* parent = node->Parent;
	Node* child = node->RightChild;
	Node* gchild = child->LeftChild;
	
	if (parent)
	{
		if (parent->Data < child->Data) parent->RightChild = child;
		else parent->LeftChild = child;
	}
	child->Parent = parent;

	child->LeftChild = node;
	node->Parent = child;

	node->RightChild = gchild;
	gchild->Parent = node;



	if (node == Root) Root = child;
}

void RedBlackTree::RotateRight(Node* node)
{
	Node* parent = node->Parent;
	Node* child = node->LeftChild;
	Node* gchild = child->RightChild;

	if (parent)
	{
		if (parent->Data < child->Data) parent->RightChild = child;
		else parent->LeftChild = child;
	}
	child->Parent = parent;

	child->RightChild = node;
	node->Parent = child;

	node->LeftChild = gchild;
	gchild->Parent = node;

	if (node == Root) Root = child;
}
