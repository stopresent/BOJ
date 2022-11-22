#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

// 이진 탐색 트리

// 이진 탐색 (binary searxh

vector<int> numbers;

void HJBinarySearch(int N)
{
	int size = numbers.size();
	int idx = size / 2;

	while (true)
	{
		cout << "midle index : " << idx << endl;

		if (idx < 0 || idx > (numbers.size() - 1))
		{
			cout << "N isn't vailed" << endl;
			break;
		}

		if (N == numbers[idx])
		{
			cout << "N is vailed" << endl;
			break;
		}

		if (N <= numbers[idx])
		{
			cout << "탐색 범위 : " << 0 << "~" << idx << endl;
			idx /= 2;
		}
		else
		{
			cout << "탐색 범위 : " << idx << "~" << numbers.size() - 1 << endl;
			idx = idx + ((numbers.size() - idx) / 2);
		}
	}
}



int main()
{
	numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	HJBinarySearch(56);
}
