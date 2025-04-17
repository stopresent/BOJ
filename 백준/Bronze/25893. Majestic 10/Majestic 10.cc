#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		cin >> a >> b >> c;
		if (a >= 10) cnt++;
		if (b >= 10) cnt++;
		if (c >= 10) cnt++;
		cout << a << " " << b << " " << c << '\n';
		if (cnt == 0) cout << "zilch" << '\n';
		if (cnt == 1) cout << "double" << '\n';
		if (cnt == 2) cout << "double-double" << '\n';
		if (cnt == 3) cout << "triple-double" << '\n';

		cout << '\n';
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