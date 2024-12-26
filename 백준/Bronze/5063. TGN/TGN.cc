#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a, b, c, n;

void solve()
{
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c;
		b -= c;
		if (a == b)
		{
			cout << "does not matter" << '\n';
		}
		else if (a > b)
		{
			cout << "do not advertise" << '\n';
		}
		else
		{
			cout << "advertise" << '\n';
		}
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