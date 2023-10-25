#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n, temp;
int start, link;
vector<vector<int>> board;
int result = INT32_MAX;
bool team[30];

void GetScores(int cnt, int pos)
{
	if (cnt == n / 2) // 절반까지 정해지면 계산
	{
		// start 팀 합계 계산
		// link 팀 합계 계산

		start = 0;
		link = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (team[i] && team[j]) start += board[i][j];
				if (team[i] == false && team[j] == false) link += board[i][j];
			}
		}

		// 최소값인지 확인
		int dif = abs(start - link);
		if (dif < result) result = dif;

		return;
	}

	for (int i = pos; i < n; i++)
	{
		team[i] = true;
		GetScores(cnt + 1, i + 1);
		team[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	board = vector<vector<int>>(n + 1, vector<int>(n + 1));

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> temp;
			board[y][x] = temp;
		}
	}

	GetScores(0, 0);

	cout << result;
}
