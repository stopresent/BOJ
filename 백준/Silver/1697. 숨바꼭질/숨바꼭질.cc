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

int n, k;
int discovered[100001];

void BFS(int here)
{
	queue<pair<int, int>> q;
	q.push({ here, 0 });
	discovered[n] = true;
	while (q.empty() == false)
	{
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (here == k)
		{
			cout << cnt;
			return;
		}
		if (here + 1 >= 0 && here + 1 < 100001)
		{
			if (discovered[here + 1] == false)
			{
				discovered[here + 1] = true;
				q.push({ here + 1, cnt + 1 });
			}
		}
		if (here - 1 >= 0 && here - 1 < 100001)
		{
			if (discovered[here - 1] == false)
			{
				discovered[here - 1] = true;
				q.push({ here - 1, cnt + 1 });
			}
		}
		if (here * 2 >= 0 && here * 2 < 100001)
		{
			if (discovered[here * 2] == false)
			{
				discovered[here * 2] = true;
				q.push({ here * 2, cnt + 1 });
			}
		}
	}
}

void solve()
{
	cin >> n >> k;

	BFS(n);
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