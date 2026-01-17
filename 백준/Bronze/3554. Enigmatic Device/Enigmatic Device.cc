#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m, k, l, r;

void solve()
{
	cin >> n;
	vector<long long> v(n);
	for (long long i = 0; i < n; i++)
		cin >> v[i];
	cin >> m;
	for (long long i = 0; i < m; i++)
	{
		cin >> k >> l >> r;
		if (k == 2)
		{
			long long sum = 0;
			for (long long j = l - 1; j < r; j++)
				sum += v[j];
			cout << sum << '\n';
		}
		else if (k == 1)
		{
			for (long long j = l - 1; j < r; j++)
			{
				long long temp = (v[j] * v[j]) % 2010;
				v[j] = temp;
			}
		}
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