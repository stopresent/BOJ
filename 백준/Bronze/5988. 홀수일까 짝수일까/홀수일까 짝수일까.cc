#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		char c = s[s.size() - 1];
		int a = c - '0';
		if ((a & 1) == 0)
		{
			cout << "even" << '\n';
		}
		else
		{
			cout << "odd" << '\n';
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