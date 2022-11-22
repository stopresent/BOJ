#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

// ÀÌÁø Å½»ö Æ®¸®

// ÀÌÁø Å½»ö (binary searxh

vector<int> numbers;

void HJBinarySearch(int N)
{
	int size = numbers.size();
	int idx = size / 2;

	while (true)
	{
		if (N == numbers[idx])
		{
			cout << "N is vailed" << endl;
			break;
		}

		if (idx <= 1 || idx >= (numbers.size() - 2))
		{
			cout << "N isn't vailed" << endl;
			break;
		}


		if (N <= numbers[idx])
		{
			idx /= 2;

		}
		else
		{
			idx = idx + idx / 2 - 1;
		}
	}
}

void binarySearch(int N)
{
	int left = 0;
	int right = (int)numbers.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		cout << "Å½»ö¹üÀ§ : " << left << "~" << right << endl;

		if (N < numbers[mid])
		{
			cout << N << "<" << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << ">" << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
			cout << "!!" << endl;
			return;
		}
	}

	cout << "¤Ğ¤Ğ" << endl;
}

int main()
{
	numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	binarySearch(15);
}
