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

using namespace std;

int c, r, k;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<int>> board;
vector<vector<int>> visited;

bool IsVailed(int y, int x)
{
	if (y >= r || y < 0 || x >= c || x < 0)
		return false;
	if (visited[y][x] == true)
		return false;

	return true;
}

void solve()
{
	cin >> c >> r >> k;
	board = vector<vector<int>>(r, vector<int>(c, 0));
	visited = vector<vector<int>>(r, vector<int>(c, 0));

	int now = 0;

	if (k > c * r)
	{
		cout << 0;
		return;
	}

	int cy = r - 1, cx = 0;
	int dir = 0;

	while (true)
	{
		if (visited[cy][cx] == false)
		{
			now++;
			visited[cy][cx] = true;
			//cout << cy << " " << cx << " " << now << endl;
		}

		if (now == k)
		{
			cout << cx + 1 << " " << r - cy;
			break;
		}

		int ny = cy + dy[dir];
		int nx = cx + dx[dir];

		if (IsVailed(ny, nx))
		{
			cy = ny;
			cx = nx;
		}
		else
		{
			dir = (dir + 1) % 4;
		}

	}
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