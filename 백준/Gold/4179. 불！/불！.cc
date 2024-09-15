#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;

int n, m;
const int INF = 987654321;
vector<vector<char>> board;
pair<int, int> person;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int fire_check[1005][1005], person_check[1005][1005];
void print()
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			cout << board[y][x];
		}
		cout << endl;
	}
	cout << endl;
}

void solve()
{
	cin >> n >> m;
	board = vector<vector<char>>(n + 1, vector<char>(m + 1));
	queue<pair<int, int>> q;
	fill(&fire_check[0][0], &fire_check[0][0] + 1005 * 1005, INF);
	for (int y = 0; y < n; ++y)
	{
		string s;
		cin >> s;
		for (int x = 0; x < m; ++x)
		{
			board[y][x] = s[x];
			if (board[y][x] == 'F')
			{
				fire_check[y][x] = 1;
				q.push({ y, x });
			}
			if (board[y][x] == 'J')
				person = { y, x };
		}
	}

	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (fire_check[ny][nx] != INF || board[ny][nx] == '#')
				continue;

			fire_check[ny][nx] = fire_check[here.first][here.second] + 1;
			q.push({ ny, nx });
		}
	}

	person_check[person.first][person.second] = 1;
	q.push({ person.first, person.second });
	int ret = 0;
	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		q.pop();
		if (here.first == 0 || here.second == 0 || here.first == n - 1 || here.second == m - 1)
		{
			ret = person_check[here.first][here.second];
			break;
		}
		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (person_check[ny][nx] != 0 || board[ny][nx] == '#')
				continue;
			if (fire_check[ny][nx] <= person_check[here.first][here.second] + 1)
				continue;

			person_check[ny][nx] = person_check[here.first][here.second] + 1;
			q.push({ ny, nx });
		}
	}

	if (ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";

	//print();
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}