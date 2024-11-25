#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int t;

long long gcd(long long a, long long b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

void solve()
{
	cin >> t;
	long long a, b;
	while (t--)
	{
		cin >> a >> b;
		cout << (a * b) / gcd(a, b) << '\n';
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