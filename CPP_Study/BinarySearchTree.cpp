#include "BinarySearchTree.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BinarySearchTree::PrintInorder(Node* node)
{
	// 전위 순회 (preorder traverse)
	// 중위 순회 (inorder)
	// 후위 순회 (postorder)

	if (node == nullptr) return;

	cout << node->key << endl;
	PrintInorder(node->left);
	PrintInorder(node->right);

}


void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node)
	{
		parent = node;

		if (key < node->key)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	newNode->parent = parent;

	if (key < parent->key)
	{
		parent->left = newNode;
	}
	else
	{
		parent->right = newNode;
	}

}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || node->key == key)
		return node;

	if (key < node->key)
	{
		Search(node->left, key);
	}
	else
	{
		Search(node->right, key);
	}
}

Node* BinarySearchTree::Search2(Node* node, int key)
{
	while (node && key != node->key)
	{
		if (key < node->key)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	return node;
}


Node* BinarySearchTree::Min(Node* node)
{
	while (node->left)
	{
		node = node->left;
	}

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right)
	{
		node = node->right;
	}

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent && parent->right == node)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr) return;

	if (node->left == nullptr)
		Replace(node, node->right);
	else if (node->right == nullptr)
		Replace(node, node->left);
	else
	{
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}

}

// u 서브트리를 v 서브트리로 교체
// 그리고 delete u
void BinarySearchTree::Replace(Node* u, Node* v)
{
	if (u->parent == nullptr)
	{
		_root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}

	if (v)
		v->parent = u->parent;

	delete u;
}


