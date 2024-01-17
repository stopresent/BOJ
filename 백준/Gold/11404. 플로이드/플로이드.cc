#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, INF = 123456789;
vector<vector<int> > dis;
void setting()
{
	cin >> n >> m;
	dis = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; ++i)
	{
		dis[i][i] = 0;
	}

	int a, b, c;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b >> c;
		if (dis[a][b] == INF)
		{
			dis[a][b] = c;
		}
		else if (dis[a][b] != INF && c < dis[a][b])
		{
			dis[a][b] = c;
		}
	}

	//for (int i = 1; i <= n; ++i)
	//{
	//	for (int j = 1; j <= n; ++j)
	//	{
	//		cout << dis[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	//cout << endl;
}

void solve()
{
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				if (dis[i][j] > dis[i][k] + dis[k][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dis[i][j] == INF)
				cout << 0 << " ";
			else
				cout << dis[i][j] << " ";
		}
		cout << '\n';
	}

	int a;
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