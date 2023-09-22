#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int resultX, resultY;
map<int, vector<int>> input;
int x, y;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		input[i].push_back(x);
		input[i].push_back(y);
	}

	if (input[0].front() == input[1].front())
		resultX = input[2].front();
	else if (input[0].front() == input[2].front())
		resultX = input[1].front();
	else
		resultX = input[0].front();

	if (input[0].back() == input[1].back())
		resultY = input[2].back();
	else if (input[0].back() == input[2].back())
		resultY = input[1].back();
	else
		resultY = input[0].back();

	cout << resultX << " " << resultY;
}
