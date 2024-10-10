#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAX = 200000;
int visited[MAX + 4];

void solve()
{
	cin >> n >> k;
	if (n == k) {
		cout << 0 << '\n';
		return;
	}

	memset(visited, -1, sizeof(visited));

	visited[n] = 0;
	queue<int> q;
	q.push(n);
	while (q.empty() == false)
	{
		int here = q.front();
		q.pop();
		for (int next : {here * 2, here - 1, here + 1}) {
			if (next >= 0 && next <= MAX && visited[next] == -1) {
				q.push(next);
				if (next == here * 2)
					visited[next] = visited[here];
				else
					visited[next] = visited[here] + 1;
			}
		}
	}

	cout << visited[k] << '\n';
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