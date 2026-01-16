#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m, j, pos, l = 1, r, ret;

void solve()
{
	cin >> n >> m >> j;
	r = m;
	for (int i = 0; i < j; i++)
	{
		r = l + m - 1;
		cin >> pos;
		if (l >= pos && r <= pos)
			continue;
		else if (pos < l)
		{
			ret += l - pos;
			l = pos;
		}
		else if (pos > r)
		{
			ret += pos - r;
			l = pos - m + 1;
		}
	}

	cout << ret;
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