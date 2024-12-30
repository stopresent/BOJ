#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int sum = 0, temp = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			sum += temp;
		}
		cout << sum << '\n';
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