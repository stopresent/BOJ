#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int r, c, res = 0;
char ch[500];
vector<vector<char>> board;
vector<vector<int>> visited;
void setting()
{
	cin >> r >> c;
	board = vector<vector<char>>(r + 1, vector<char>(c + 1));
	visited = vector<vector<int>>(r + 1, vector<int>(c + 1));

	string str;
	for (int i = 1; i <= r; ++i)
	{
		cin >> str;
		for (int j = 0; j < str.size(); ++j)
		{
			board[i][j + 1] = str[j];
		}
	}

	//for (int i = 1; i <= r; ++i)
	//{
	//	for (int j = 1; j <= c; ++j)
	//	{
	//		cout << board[i][j];
	//	}

	//	cout << endl;
	//}
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int seqSize = 1;
void DFS(pair<int, int> here)
{
	ch[seqSize++] = board[here.first][here.second];
	res = max(res, seqSize);
	//visited[here.first][here.second] = 1;

	//cout << endl;
	//cout << "현재 ch 상태 " << endl;
	//for (int i = 1; i <= seqSize; ++i)
	//{
	//	cout << ch[i] << " ";
	//}
	//cout << endl;

	for (int i = 0; i < 4; ++i)
	{
		int ny = here.first + dy[i];
		int nx = here.second + dx[i];

		if (ny < 1 || nx < 1 || ny > r || nx > c)
			continue;
		if (visited[ny][nx] == 1)
			continue;
		bool flag = false;
		for (int j = 1; j <= seqSize; ++j)
		{
			if (ch[j] == board[ny][nx])
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
			continue;

		visited[ny][nx] = 1;
		DFS({ ny, nx });
		visited[ny][nx] = 0;
		ch[--seqSize] = ' ';
	}
}

void solve()
{
	DFS({ 1, 1 });
	cout << res - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	solve();

	return 0;
}