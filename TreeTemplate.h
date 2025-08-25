#pragma once

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
	};

	using Node = typename Tree<T>::Node;

	Tree() { Root = nullptr; }
	virtual ~Tree() {}

	virtual bool Insert(T) = 0;
	virtual bool Delete(T) = 0;
	Node* GetRoot() { return Root; }

protected:
	Node* Root;
};