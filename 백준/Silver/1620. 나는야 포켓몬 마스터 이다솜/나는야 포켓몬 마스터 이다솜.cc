#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
string a[100004];
unordered_map<string, int> um2;
string s;

bool isNumber(string s)
{
	if (s.empty())
		return false;
	for (char c : s)
		if (!isdigit(c)) return false;
	return true;
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		a[i] = s;
		um2[s] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		bool flag = isNumber(s);
		if (flag)
		{
			int idx = stoi(s);
			cout << a[idx] << '\n';
		}
		else
		{
			cout << um2[s] << '\n';
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