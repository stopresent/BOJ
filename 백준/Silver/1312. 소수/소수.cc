#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a, b, n;

void solve()
{
	cin >> a >> b >> n;
	a = a % b;

	for (int i = 0; i < n - 1; ++i)
	{
		a *= 10;
		a = a % b;
		//cout << a << endl;
	}

	a *= 10;

	cout << a / b;
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