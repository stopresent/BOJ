#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, d, p;
char who;
void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> who;

		if (who == 'D')
			d++;
		else
			p++;

		if (abs(d - p) >= 2)
			break;
	}

	cout << d << ":" << p;
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