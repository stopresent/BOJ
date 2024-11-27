#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int x1, x2, a, b, c, d, e;
	cin >> x1 >> x2 >> a >> b >> c >> d >> e;
	b -= d;
	c -= e;
	a /= 3;
	b /= 2;
	
	cout << (a * x2 * x2 * x2 + b * x2 * x2 + c * x2) - (a * x1 * x1 * x1 + b * x1 * x1 + c * x1);
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