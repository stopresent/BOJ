#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> ans;

int v;

bool IsBinggo()
{
	int binggoCount = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (ans[i][0] && ans[i][0 + 1] && ans[i][0 + 2] && ans[i][0 + 3] && ans[i][0 + 4])
			binggoCount++;
		if (ans[0][i] && ans[0 + 1][i] && ans[0 + 2][i] && ans[0 + 3][i] && ans[0 + 4][i])
			binggoCount++;
	}

	// 대각선
	if (ans[0][0] && ans[1][1] && ans[2][2] && ans[3][3] && ans[4][4])
		binggoCount++;
	if (ans[0][4] && ans[1][3] && ans[2][2] && ans[3][1] && ans[4][0])
		binggoCount++;

	if (binggoCount >= 3)
		return true;

	return false;
}

int ansValue = 0;
void WriteBinggo()
{
	for (int i = 0; i < 25; ++i)
	{
		ansValue++;

		cin >> v;

		for (int y = 0; y < 5; ++y)
		{
			for (int x = 0; x < 5; ++x)
			{
				if (board[y][x] == v)
				{
					ans[y][x] = true;
					if (IsBinggo())
					{
						cout << ansValue;
						return;
					}
				}
			}
		}
	}
	
}

void CreateBoard()
{
	board = vector<vector<int>>(5, vector<int>(5));
	ans = vector<vector<bool>>(5, vector<bool>(5, false));

	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			cin >> v;
			board[y][x] = v;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	CreateBoard();
	WriteBinggo();
}
