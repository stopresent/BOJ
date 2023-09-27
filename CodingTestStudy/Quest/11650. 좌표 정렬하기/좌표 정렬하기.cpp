#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N, x, y;


int main()
{
	cin >> N;

	vector<int[2]> test;
	vector<vector<int>> coordinate;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		cin >> y;
		coordinate.push_back({ x, y });
	}

	sort(coordinate.begin(), coordinate.end());



	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < coordinate[x].size(); y++)
		{
			cout << coordinate[x][y] << ' ';
		}
		cout << '\n';
	}

	//sort(coordinate.begin(), coordinate.end());
}
