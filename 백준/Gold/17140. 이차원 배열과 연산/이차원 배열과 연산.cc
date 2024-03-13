#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Num
{
	int num, cnt;
	bool operator<(const Num& other)
	{
		if (cnt == other.cnt)
			return num < other.num;
		else
			return cnt < other.cnt;
	}
};

int r, c, k, total_time = 0;
int r_len = 3, c_len = 3;
vector<vector<int>> board;
vector<Num> numbers;

void R()
{
	// 각 수가 얼만큼 나왔는지 알아야한다.
	int max_r_len = 0;
	int max_c_len = 0; // 이게 갱신됨.
	for (int y = 1; y <= r_len; ++y)
	{
		numbers.clear();
		numbers.resize(101);
		for (int i = 1; i <= 100; ++i)
			numbers[i].num = i;

		for (int x = 1; x <= c_len; ++x)
		{
			numbers[board[y][x]].cnt++;
		}
		sort(numbers.begin(), numbers.end());

		board[y].clear();
		board[y].push_back(0);
		int len = 0;
		for (int i = 1; i <= 100; ++i)
		{
			if (numbers[i].cnt == 0 || numbers[i].num == 0)
				continue;
			board[y].push_back(numbers[i].num);
			len++;
			board[y].push_back(numbers[i].cnt);
			len++;
		}
		for (int i = len; i <= 100; ++i)
			board[y].push_back(0);

		max_c_len = max(max_c_len, len);
	}

	c_len = max(c_len, max_c_len);
}

void C()
{
	int max_r_len = 0;
	int max_c_len = 0;
	for (int x = 1; x <= c_len; ++x)
	{
		numbers.clear();
		numbers.resize(101);
		for (int i = 1; i <= 100; ++i)
			numbers[i].num = i;

		for (int y = 1; y <= r_len; ++y)
		{
			numbers[board[y][x]].cnt++;
		}
		sort(numbers.begin(), numbers.end());
		board[0][x] = 0;
		int len = 0;
		int idx = 1;
		for (int i = 1; i <= 100; ++i)
		{
			if (numbers[i].cnt == 0 || numbers[i].num == 0)
				continue;
			board[idx][x] = numbers[i].num;
			idx++;
			len++;
			board[idx][x] = numbers[i].cnt;
			idx++;
			len++;
		}
		max_r_len = max(max_r_len, len);
		for (int i = len + 1; i <= 100; ++i)
		{
			board[i][x] = 0;
		}

	}

	r_len = max(r_len, max_r_len);

}

void solve()
{
	// 입력값 받기.
	cin >> r >> c >> k;
	board = vector<vector<int>>(101, vector<int>(101));
	for (int y = 1; y <= 3; ++y)
	{
		for (int x = 1; x <= 3; ++x)
		{
			cin >> board[y][x];
		}
	}

	for (int i = 0; i <= 101; ++i)
	{
		if (i == 101)
		{
			cout << -1;
			break;
		}
		if (board[r][c] == k)
		{
			cout << i;
			break;
		}

		if (r_len >= c_len)
			R();
		else
			C();
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