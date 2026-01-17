#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m, k, ny, nx, cnt;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<int>> v;
vector<vector<int>> visited;

int BFS(int y, int x)
{
	int ret = 1;
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({y, x});
	while (q.size())
	{
		pair<int, int> f = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ny = f.first + dy[i];
			nx = f.second + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx] || v[ny][nx] == 1) continue;
			visited[ny][nx] = visited[f.first][f.second] + 1;
			q.push({ ny, nx });
			ret++;
		}
	}
	return ret;
}

void solve()
{
	cin >> n >> m >> k;
	v = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<int>>(n, vector<int>(m, 0));
	int x_0, y_0, x_1, y_1;
	for (int i = 0; i < k; i++)
	{
		cin >> x_0 >> y_0 >> x_1 >> y_1;
		for (int y = y_0; y < y_1; y++)
		{
			for (int x = x_0; x < x_1; x++)
			{
				v[y][x] = 1;
			}
		}
	}

	vector<int> ans;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (v[y][x] == 0 && !visited[y][x])
			{
				ans.push_back(BFS(y, x));
				cnt++;
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << cnt << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
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