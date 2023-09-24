#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int a, b, c;

map<int, int[3]> _threeSides;

void CheckThreeSidex(int a, int b, int c)
{
	int sum = a + b + c;
	int max = 0;
	if (max < a) max = a;
	if (max < b) max = b;
	if (max < c) max = c;

	if ((sum - max) <= max)
	{
		cout << "Invalid" << endl;
		return;
	}

	if (a == b && b == c)
	{
		cout << "Equilateral" << endl;
		return;
	}
	if (a != b && b != c && a != c)
	{
		cout << "Scalene" << endl;
		return;
	}
	else
	{
		cout << "Isosceles" << endl;
		return;
	}
}

int main()
{
	int i = 0;
	while (true)
	{
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			break;

		_threeSides[i][0] = a;
		_threeSides[i][1] = b;
		_threeSides[i][2] = c;

		i++;
	}

	for (int index = 0; index < i; index++)
	{
		CheckThreeSidex(_threeSides[index][0], _threeSides[index][1], _threeSides[index][2]);
	}
}
