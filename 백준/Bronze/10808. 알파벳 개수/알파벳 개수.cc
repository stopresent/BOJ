#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[26];
string str;

void solve()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		a[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		cout << a[i] << ' ';
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