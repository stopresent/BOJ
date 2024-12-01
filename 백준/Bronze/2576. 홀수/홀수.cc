#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int sum = 0, mn = INT_MAX;

void solve()
{
	int temp;
	for (int i = 0; i < 7; ++i)
	{
		cin >> temp;
		if ((temp & 1) == 1)
		{
			sum += temp;
			mn = min(mn, temp);
		}
	}
	if (sum != 0)
		cout << sum << '\n';
	else
	{
		cout << -1 << '\n';
		return;
	}

	cout << mn;
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