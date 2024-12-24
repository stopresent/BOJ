#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a, b, c, n, ret = 0;

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		int sum = 0;
		if (a == b && b == c)
		{
			sum = 10000 + a * 1000;
		}
		else if (a == b || b == c || a == c)
		{
			if (a == b)
				sum = 1000 + a * 100;
			if (b == c)
				sum = 1000 + b * 100;
			if (a == c)
				sum = 1000 + c * 100;
		}
		else
		{
			int mx = max(a, b);
			mx = max(mx, c);
			sum = mx * 100;
		}

		//cout << sum << endl;
		ret = max(sum, ret);
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