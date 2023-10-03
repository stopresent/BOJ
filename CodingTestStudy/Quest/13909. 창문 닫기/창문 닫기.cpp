#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

long long N;

int main()
{
	cin >> N;

	// 24
	// 1 4 9 16 -> 4
	// 다시 말해 N내의 제곱수를 구하면됨.

	int result = 0;
	int sqr = 1;
	int index = 1;
	while (true)
	{
		sqr = index * index;

		if (sqr > N)
			break;

		index++;
	}
	cout << index - 1;
}
