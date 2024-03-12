#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>

using namespace std;

int _loopCnt = 0, _document = 0;
int _t, _h, _w, cnt = 0;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<char>> _board;
vector<pair<int, int>> _gate;
vector<vector<bool>> _visited;
map<char, bool> _inventory;

bool BFS(int y, int x)
{
	bool getKey = false;
	if (_board[y][x] >= 'A' && _board[y][x] <= 'Z')
	{
		// 인벤토리 확인.
		if (_inventory[_board[y][x] + 32] == true)
			_board[y][x] = '.';
		else
			return false;
	}
	else if (_board[y][x] >= 'a' && _board[y][x] <= 'z')
	{
		_inventory[_board[y][x]] = true;
		_board[y][x] = '.';
	}
	else if (_board[y][x] == '$')
	{
		cnt++;
		_board[y][x] = '.';
	}

	queue<pair<int, int>> q;
	q.push({ y, x });
	_visited[y][x] = true;

	pair<int, int> here;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || ny >(_h - 1) || nx < 0 || nx >(_w - 1))
				continue;
			if (_visited[ny][nx])
				continue;
			if (_board[ny][nx] == '*')
				continue;

			if (_board[ny][nx] == '.')
			{
				_visited[ny][nx] = true;
				q.push({ ny, nx });
			}
			else if (_board[ny][nx] >= 'A' && _board[ny][nx] <= 'Z')
			{
				// 인벤토리 확인 필요.
				if (_inventory[_board[ny][nx] + 32] == true)
				{
					_board[ny][nx] = '.';
					_visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
			else if (_board[ny][nx] >= 'a' && _board[ny][nx] <= 'z')
			{
				_visited[ny][nx] = true;
				q.push({ ny, nx });
				_inventory[_board[ny][nx]] = true;
				_board[ny][nx] = '.';
				getKey = true;
			}
			else if (_board[ny][nx] == '$')
			{
				_visited[ny][nx] = true;
				q.push({ ny, nx });
				_board[ny][nx] = '.';
				cnt++;

				if (cnt == _document)
					return false;
			}
		}
	}

	_visited.clear();
	_visited = vector<vector<bool>>(_h, vector<bool>(_w));

	if (getKey == true)
		return true;
	else
		return false;
}

void solve()
{
	cin >> _t;

	for (int i = 0; i < _t; ++i)
	{
		cin >> _h >> _w;
		cnt = 0;
		_board.clear();
		_board = vector<vector<char>>(_h, vector<char>(_w));
		_visited.clear();
		_visited = vector<vector<bool>>(_h, vector<bool>(_w));
		_gate.clear();
		_inventory.clear();

		_loopCnt = 0;
		_document = 0;

		//_map.clear();
		// 평면도 입력
		for (int y = 0; y < _h; ++y)
		{
			string str;
			cin >> str;
			for (int x = 0; x < _w; ++x)
			{
				_board[y][x] = str[x];
				if ((x == 0 && _board[y][x] != '*') || (y == 0 && _board[y][x] != '*') || (x == _w - 1 && _board[y][x] != '*') || (y == _h - 1 && _board[y][x] != '*'))
					_gate.push_back({ y, x });
				if (_board[y][x] >= 'A' && _board[y][x] <= 'Z')
					_loopCnt++;
				if (_board[y][x] == '$')
					_document++;
			}
		}

		for (int key = 'a'; key < 'a' + 26; ++key)
		{
			_inventory[key] = false;
		}

		// 가지고 있는 열쇠
		string keys;
		cin >> keys;
		for (int key = 0; key < keys.size(); ++key)
		{
			_inventory[keys[key]] = true;
		}

		for (int l = 0; l < _gate.size(); ++l)
		{
			for (int k = 0; k < _gate.size(); ++k)
			{
				if (cnt == _document)
					break;

				if (BFS(_gate[k].first, _gate[k].second) == true)
				{
					k--;
				}

			}
		}
		cout << cnt << '\n';
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