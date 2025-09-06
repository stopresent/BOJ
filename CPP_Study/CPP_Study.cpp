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
        // 1s 대신 std::chrono::seconds(1)로 변경
        this_thread::sleep_for(std::chrono::seconds(1));
	}

	bst.Insert(10);
	bst.Print();
	this_thread::sleep_for(std::chrono::seconds(1));

	bst.Insert(20);
	bst.Print();
	this_thread::sleep_for(std::chrono::seconds(1));

}
