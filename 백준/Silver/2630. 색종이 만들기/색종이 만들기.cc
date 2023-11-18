#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n, white = 0, blue = 0;
vector<vector<int>> board;

void CreateBoard()
{
	cin >> n;

	board = vector<vector<int>>(n, vector<int>(n));

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			cin >> board[y][x];
		}
	}
}

void solve(int y, int x, int size)
{
	int check = board[y][x];
	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			if (check == 0 && board[i][j] == 1)
				check = 2;
			else if (check == 1 && board[i][j] == 0)
				check = 2;
			if (check == 2)
			{
				solve(y, x, size / 2);
				solve(y, x + size / 2, size / 2);
				solve(y + size / 2, x, size / 2);
				solve(y + size / 2, x + size / 2, size / 2);
				return;
			}
		}
	}
	if (check == 0)
		white++;
	else
		blue++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	CreateBoard();
	solve(0, 0, n);
	cout << white << '\n';
	cout << blue << '\n';
}
