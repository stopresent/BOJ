#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int t;

void solve()
{
	cin >> t;
	while (t--)
	{
		int sum = 0, temp = 0, mn = INT_MAX;
		for (int i = 0; i < 7; ++i)
		{
			cin >> temp;
			if ((temp & 1) == 0)
			{
				mn = min(mn, temp);
				sum += temp;
			}
		}

		cout << sum << " " << mn << '\n';
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