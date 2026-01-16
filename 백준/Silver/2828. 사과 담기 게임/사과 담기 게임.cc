#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m, j, pos, mn_window = 1, mx_window, move_cnt;

void solve()
{
	cin >> n >> m >> j;
	mx_window = m;
	for (int i = 0; i < j; i++)
	{
		cin >> pos;
		if (mn_window >= pos && mx_window <= pos)
			continue;
		else if (pos < mn_window)
		{
			int dist = mn_window - pos;
			move_cnt += dist;
			mn_window -= dist;
			mx_window -= dist;
		}
		else if (pos > mx_window)
		{
			int dist = pos - mx_window;
			move_cnt += dist;
			mn_window += dist;
			mx_window += dist;
		}
	}

	cout << move_cnt;
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