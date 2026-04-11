#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[26];
string s = "PREDAJA";

void solve() {
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		cnt[str[0] - 'a']++;
	}

	bool flag = false;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5)
		{
			flag = true;
			cout << (char)(i + 'a');
		}
	}

	if (!flag)
	{
		cout << s;
	}
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}