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

const int MAX = 100001;
int t, n, cnt;
vector<int> graph;
vector<bool> visited;
vector<bool> done;

void isCycle(int here)
{
	visited[here] = true;
	int next = graph[here];

	if (visited[next] == false)
		isCycle(next);
	else if (done[next] == false)
	{
		for (int i = next; i != here; i = graph[i])
			cnt++;
		cnt++;
	}

	done[here] = true;
}

void solve()
{
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cin >> n;
		graph.clear();
		graph.resize(n + 1);
		visited.clear();
		visited.resize(MAX);
		done.clear();
		done.resize(MAX);
		for (int j = 1; j <= n; ++j)
		{
			cin >> graph[j];
		}
		for (int i = 1; i <= n; ++i)
		{
			if (visited[i] == false)
				isCycle(i);
		}

		cout << n - cnt << '\n';
		cnt = 0;
		visited.clear();
		visited.resize(MAX);
		done.clear();
		done.resize(MAX);
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