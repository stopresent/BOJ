#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

long long n, sum;

void solve()
{
	while (cin >> n)
	{
		sum += n;
	}
	cout << sum;
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