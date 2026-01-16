#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s;
char c[] = { 'a', 'e', 'i', 'o', 'u' };

bool check1(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (s[i] == c[j])
				return true;
		}
	}

	return false;
}

bool check2(string s)
{
	for (int i = 0; i + 2 < s.size(); i++)
	{
		int cnt = 0;
		for (int j = i; j < i + 3; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (c[k] == s[j])
					cnt++;
			}
		}

		if (cnt == 0 || cnt == 3)
			return false;
	}

	return true;
}

bool check3(string s)
{
	for (int i = 0; i + 1 < s.size(); i++)
	{
		if (s[i] == s[i + 1])
		{
			if (s[i] == 'e' || s[i] == 'o')
				continue;
			return false;
		}
	}

	return true;
}

void solve()
{
	while (true)
	{
		cin >> s;
		if (s == "end")
			break;
		if (check1(s) && check2(s) && check3(s))
			cout << "<" << s << "> is acceptable." << '\n';
		else
			cout << "<" << s << "> is not acceptable." << '\n';
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