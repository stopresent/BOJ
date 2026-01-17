#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s;
bool isVowel(int idx)
{
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

void solve()
{
	while (true)
	{
		cin >> s;
		if (s == "end") break;
		int lcnt = 0, vcnt = 0;
		bool flag = false, is_inclusive_v = false;
		int prev = -1;
		for (int i = 0; i < s.size(); i++)
		{
			int idx = s[i];
			if (isVowel(idx))
			{
				vcnt++;
				lcnt = 0;
				is_inclusive_v = true;
			}
			else
			{
				lcnt++;
				vcnt = 0;
			}
			if (vcnt == 3 || lcnt == 3) flag = true;
			if (i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o'))
				flag = true;
			prev = idx;
		}
		if (is_inclusive_v == false)
			flag = true;
		if (flag)
			cout << "<" << s << "> is not acceptable.\n";
		else
			cout << "<" << s << "> is acceptable.\n";
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