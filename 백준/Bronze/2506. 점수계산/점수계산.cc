#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, ret = 0;
void solve()
{
	cin >> n;
	int a, ch = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		if (a == 1)
		{
			ret += ch++;
		}
		else
		{
			ch = 1;
		}
	}

	cout << ret;
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