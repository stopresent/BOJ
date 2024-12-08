#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int t;

void solve()
{
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;

		if (n == 1)
		{
			int temp;
			cin >> temp;
			cout << temp << '\n';
			continue;
		}

		vector<int> v(n);
		long long ret = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			for (int j = i - 1; j >= 0; --j)
			{
				ret += gcd(v[i], v[j]);
			}
		}
		cout << ret << '\n';
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