#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
string str;

void solve()
{
	cin >> n >> str;
	int idx = str.find('*');
	string pre = str.substr(0, idx);
	string suf = str.substr(idx + 1);
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s.size() < (pre.size() + suf.size()))
		{
			cout << "NE" << '\n';
			continue;
		}
		string s_pre = s.substr(0, pre.size());
		string s_suf = s.substr(s.size() - suf.size());
		if (pre == s_pre && suf == s_suf)
			cout << "DA" << '\n';
		else
			cout << "NE" << '\n';
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