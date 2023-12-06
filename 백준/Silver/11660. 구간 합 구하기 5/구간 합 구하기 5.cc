#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> board(1025, vector<int>(1025));
vector<vector<int>> cache(1025, vector<int>(1025));

void solve()
{
	cin >> n >> m;

	for (int y = 1; y <= n; ++y)
		for (int x = 1; x <= n; ++x)
		{
			cin >> board[y][x];
			cache[y][x] = cache[y - 1][x] + cache[y][x - 1] - cache[y - 1][x - 1] + board[y][x];
		}

	int x1, y1, x2, y2;
	int sum;
	for (int i = 0; i < m; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		sum = cache[x2][y2] - cache[x1 - 1][y2] - cache[x2][y1 - 1] + cache[x1 - 1][y1 - 1];

		cout << sum << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}