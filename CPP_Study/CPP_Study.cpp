#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;
#include "BinarySearchTree.h"
#include <thread>

// 이진 탐색 트리

// 이진 탐색 (binary search)

int main()
{
	srand(time(NULL));

	BinarySearchTree bst;

	bst.Insert(50);
	bst.Print();

	for (int i = 0; i < 20; i++) 
	{
		bst.Insert(rand() % 100);
		bst.Print();
		this_thread::sleep_for(1s);
	}

	bst.Insert(10);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(25);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(40);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(50);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(10);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(25);
	bst.Print();
	this_thread::sleep_for(1s);


}
