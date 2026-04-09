#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s;

void solve() {
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - 1 - i])
		{
			cout << 0;
			return;
		}
	}
	cout << 1;
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}