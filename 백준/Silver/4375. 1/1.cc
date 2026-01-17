#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, ret;
int check(int n)
{
	long long check = 1;
	int ret = 1;
	while (true)
	{
		if (check % n == 0)
		{
			return ret;
		}
		check %= n;
		check = 10 * check + 1;
		ret++;
	}
}

void solve()
{
	while (cin >> n)
	{
		cout << check(n) << '\n';
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