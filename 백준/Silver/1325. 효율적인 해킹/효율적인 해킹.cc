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

int n, m, cnt = 0;

struct node
{
	int value;
	vector<node*> parents;
	vector<node*> children;
};

vector<node> nodes;
vector<int> ans;
vector<int> visited;
vector<int> dp;

int dfs(int index)
{
	visited[index] = 1;
	int ret = 1;
	for (int i = 0; i < nodes[index].children.size(); ++i)
	{
		if (visited[nodes[index].children[i]->value] == 1)
			continue;
		ret += dfs(nodes[index].children[i]->value);
	}

	return ret;
}

void solve()
{
	cin >> n >> m;
	nodes = vector<node>(n + 1);
	ans = vector<int>(n + 1);
	visited = vector<int>(n + 1);
	dp = vector<int>(n + 1);
	for (int i = 0; i < n; ++i)
	{
		nodes[i + 1].value = i + 1;
	}

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		nodes[u].parents.push_back(&nodes[v]);
		nodes[v].children.push_back(&nodes[u]);
	}

	int mc = -1;
	for (int i = 0; i < n; ++i)
	{
		visited = vector<int>(n + 1);
		dp[i + 1] = dfs(i + 1);
		mc = max(dp[i + 1], mc);
	}

	for (int i = 0; i < n; ++i)
	{
		if (dp[i + 1] == mc)
			cout << i + 1 << " ";
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