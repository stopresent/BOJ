#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char ROT13(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 13) % 26 + 'a';
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 13) % 26 + 'A';
	else
		return c;
}

void solve() {
	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		cout << ROT13(s[i]);
	}
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}