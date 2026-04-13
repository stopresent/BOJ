#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, cnt[26];
string s = "PREDAJA", ret = "";

void solve() {
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		cnt[str[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5) ret += (char)(i + 'a');
	}

	if (ret.size()) cout << ret;
	else cout << s;

}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}