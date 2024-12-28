#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	cin >> n;
	int a;
	while (n--)
	{
		cin >> a;
		int i = 0;
		while (a > 0)
		{
			if (a % 2 == 1)
			{
				cout << i << " ";
			}
			i++;
			a /= 2;
		}
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