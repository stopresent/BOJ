#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int A, B;
map<int, int> aMap;
int tempInt;
int overlap = 0;

int main()
{
	cin >> A >> B;

	for (int i = 0; i < A; i++)
	{
		cin >> tempInt;
		aMap[tempInt] = 1;
	}

	for (int i = 0; i < B; i++)
	{
		cin >> tempInt;
		if (aMap[tempInt] == 1)
		{
			overlap++;
		}
	}

	cout << A + B - overlap * 2 << '\n';
}
