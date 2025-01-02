#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, p;

void solve()
{
	cin >> a >> b >> c >> d >> p;
	int x = a * p;
	int y = b;
	if (p > c)
	{
		y += (p - c) * d;
	}
	int ret = min(x, y);
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