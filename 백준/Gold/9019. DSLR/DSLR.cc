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

using namespace std;

// DSLR

int t, a, b;
bool visited[10010];
char ch[100];

int D(int n)
{
	return (2 * n) % 10000;
}

int S(int n)
{
	int ret = n;
	ret--;
	if (ret == -1)
		ret = 9999;
	return ret;
}

int L(int n)
{
	int ret = n;
	int temp = n / 1000;
	ret = (n % 1000) * 10 + temp;
	return ret;
}

int R(int n)
{
	int temp = n % 10;
	temp *= 1000;
	return (n / 10) + temp;
}

void BFS()
{
	queue<pair<int, string>> q;
	q.push({ a, "" });

	while (q.empty() == false)
	{
		int num = q.front().first;
		string str = q.front().second;
		q.pop();

		if (num == b)
		{
			cout << str << '\n';
			return;
		}

		int d, s, l, r;
		d = D(num);
		l = L(num);
		r = R(num);
		s = S(num);
		if (visited[d] == false)
		{
			visited[d] = true;
			q.push({ d, str + "D" });
		}

		if (visited[s] == false)
		{
			visited[s] = true;
			q.push({ s, str + "S" });
		}

		if (visited[l] == false)
		{
			visited[l] = true;
			q.push({ l, str + "L" });
		}

		if (visited[r] == false)
		{
			visited[r] = true;
			q.push({ r, str + "R" });
		}

	}
}

void solve()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		memset(&visited, false, sizeof(visited));
		BFS();

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