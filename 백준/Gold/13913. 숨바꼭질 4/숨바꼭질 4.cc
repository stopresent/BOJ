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

int n, k, ret;
const int MAX = 200000;
int visited[MAX + 4];
int parent[MAX + 4];

void solve()
{
	cin >> n >> k;

	visited[n] = 1;
	queue<int> q;
	q.push(n);
	while (q.empty() == false)
	{
		int here = q.front();
		q.pop();

		if (here == k) {
			ret = visited[k];
			break;
		}

		for (int next : {here - 1, here + 1, here * 2})
		{
			if (next < 0 || next >= MAX || visited[next])
				continue;
			visited[next] = visited[here] + 1;
			parent[next] = here;
			q.push(next);
		}
	}

	vector<int> path;
	for (int i = k; i != n; i = parent[i])
	{
		path.push_back(i);
	}
	path.push_back(n);

	cout << ret - 1 << '\n';
	reverse(path.begin(), path.end());
	for (int i : path)
		cout << i << " ";
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