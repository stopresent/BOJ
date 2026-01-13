#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string str;

void solve()
{
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'u')
		{
			int a = 3;
		}
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] > (('a' + 'z') / 2))
				str[i] = str[i] + 13 - 26;
			else
				str[i] = str[i] + 13;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] > (('A' + 'Z') / 2))
				str[i] = str[i] + 13 - 26;
			else
				str[i] = str[i] + 13;
		}
	}

	cout << str;
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