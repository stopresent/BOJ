#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s;

void solve() {
	cin >> s;
	string temp = s;
	reverse(s.begin(), s.end());
	if (s == temp) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}