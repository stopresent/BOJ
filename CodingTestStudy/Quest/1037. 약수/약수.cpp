#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
	int N, tempInt;
	int minNum = 1000000;
	int maxNum = 1;

	cin >> N;

	while (N > 0)
	{
		cin >> tempInt;

		if (minNum > tempInt) minNum = tempInt;
		if (maxNum < tempInt) maxNum = tempInt;

		N--;
	}

	cout << minNum * maxNum << endl;
}
