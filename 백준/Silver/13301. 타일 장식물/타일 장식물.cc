#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	cin >> n;
	vector<long long> v(n + 1);
	v[1] = 4;
	v[2] = 6;
	for (int i = 3; i <= n; ++i)
	{
		v[i] = v[i - 1] + v[i - 2];
	}

	cout << v[n];
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