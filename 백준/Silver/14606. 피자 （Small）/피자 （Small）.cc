#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, ret = 0;

void div(int x)
{
	if (x == 1)
		return;

	if ((x & 1) == 1)
	{
		ret += (x / 2 + 1) * (x / 2);
		div(x / 2 + 1);
		div(x / 2);
	}
	else
	{
		ret += (x / 2) * (x / 2);
		div(x / 2);
		div(x / 2);
	}	
}

void solve()
{
	cin >> n;
	div(n);
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