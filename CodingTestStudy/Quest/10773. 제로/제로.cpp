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

	stack<int> s;

	cin >> N;

	while (true)
	{
		if (N == 0)
			break;

		cin >> tempInt;

		if (tempInt == 0)
			s.pop();
		else
			s.push(tempInt);

		N--;
	}

	int sum = 0;

	while (!s.empty())
	{
		int element = s.top();
		sum += element;
		s.pop();
	}

	cout << sum;
}
