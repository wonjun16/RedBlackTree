#pragma once

enum COLOR
{
	BLACK = 0,
	RED
};

template <class T>
class Tree
{
public:
	struct Node
	{
		T Data;
		Node* LeftChild;
		Node* RightChild;
		Node* Parent;

		COLOR Color;
	};

	using Node = typename Tree<T>::Node;

	Tree() { Root = nullptr; }
	virtual ~Tree() {}

	virtual bool Insert(T) = 0;
	virtual bool Delete(T) = 0;
	Node* GetRoot() { return Root; }
	Node* GetNil() { return Nil; }

protected:
	Node* Root;
	Node* Nil;
};