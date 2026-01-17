#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string str;
string key;

void solve()
{
	getline(cin, str);
	cin >> key;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			str[i] = ' ';
			continue;
		}

		int idx = (i % key.size());
		int move = (int)(key[idx] - 'a' + 1);
		int temp = (int)str[i] - move;
		if (temp < (int)'a')
			temp += 26;
		str[i] = (char)temp;
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