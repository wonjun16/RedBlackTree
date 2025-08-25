#include "BinaryTree.h"
#include <stdio.h>

BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::~BinaryTree()
{

}

bool BinaryTree::Insert(int data)
{
	if (!root) {
		root = new Node();
		root->Data = data;
		root->LeftChild = nullptr;
		root->RightChild = nullptr;
		root->Parent = nullptr;
		return true;
	}

    Node* temp = root;
    Node* parent = nullptr;
    while (temp) 
    {
        parent = temp;
        if (temp->Data == data) return false;
        if (data < temp->Data)
            temp = temp->LeftChild;
        else
            temp = temp->RightChild;
    }

    Node* node = new Node();
    node->Data = data;
    node->LeftChild = nullptr;
    node->RightChild = nullptr;
    node->Parent = parent;

    if (data < parent->Data)
        parent->LeftChild = node;
    else
        parent->RightChild = node;

    return true;
}

bool BinaryTree::Delete(int target)
{
    if (!root) return false;

	Node* temp = root;
    Node* deletenode = nullptr;
    Node* deleteparent = nullptr;

    while (temp != nullptr)
    {
        
        if (temp->Data == target) break;
        else
        {
            deleteparent = temp;
            if (temp->Data < target) temp = temp->LeftChild;
            else if (temp->Data > target) temp = temp->RightChild;
        }
    }
    if (!temp) return false;

    if (temp->LeftChild == nullptr && temp->RightChild == nullptr)
    {
        deletenode = temp;
        if (deletenode->Data < deleteparent->Data) deleteparent->LeftChild = nullptr;
        else deleteparent->RightChild = nullptr;
    }
    else
    {
        deleteparent = temp;
        if (temp->LeftChild)
        {
            deletenode = temp->LeftChild;
            while (deletenode->RightChild)
            {
                deleteparent = deletenode;
                deletenode = deletenode->RightChild;
            }
        }
        else
        {
            deletenode = temp->RightChild;
            while (deletenode->LeftChild)
            {
                deleteparent = deletenode;
                deletenode = deletenode->LeftChild;
            }
        }
        
        if (deletenode->Data < deleteparent->Data) deleteparent->LeftChild = nullptr;
        else deleteparent->RightChild = nullptr;
        temp->Data = deletenode->Data;
    }

    delete deletenode;
    deletenode = nullptr;

	return true;
}

void BinaryTree::ShowTree(Node* node)
{
    if (node == nullptr) return;
    ShowTree(node->LeftChild);
    printf("%d ", node->Data);
    ShowTree(node->RightChild);
}
