#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

map<string, int> cache;

int main()
{
	int N;
	string Name;
	int helloCount = 0;
	int enterCount = 0;
	cin >> N;

	while (N > 0)
	{
		cin >> Name;

		if (Name == "ENTER")
		{
			enterCount++;
			N--;
			continue;
		}

		if (cache[Name] != enterCount)
		{
			cache[Name] = enterCount;
			helloCount++;
		}

		N--;
	}

	cout << helloCount;

}
