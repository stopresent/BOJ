#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long long DIV = 1000000007;
long long n;

pair<long long, long long> fib(long long n)
{
	if (n == 0)
		return { 0, 1 };
	pair<long long, long long> p = fib(n >> 1);
	long long c = (p.first * ((2 * p.second % DIV + DIV - p.first) % DIV)) % DIV;
	long long d = (p.first * p.first % DIV + p.second * p.second % DIV) % DIV;
	if (n & 1)
		return { d, (c + d) % DIV };
	else
		return { c, d };
}

void solve()
{
	cin >> n;
	pair<long long, long long> ret = fib(n);
	cout << ret.first;
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