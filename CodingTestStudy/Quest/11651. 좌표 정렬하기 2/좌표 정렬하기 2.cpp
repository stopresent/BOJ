#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N, x, y;

vector<vector<int>> coordinate;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		cin >> y;
		coordinate.push_back({ y, x });
	}

	sort(coordinate.begin(), coordinate.end());

	for (int y = 0; y < N; y++)
	{
		for (int x = coordinate[y].size() - 1; x >= 0; x--)
		{
			// 위치 바꾸기
			cout << coordinate[y][x] << ' ';
		}
		cout << '\n';
	}

}
