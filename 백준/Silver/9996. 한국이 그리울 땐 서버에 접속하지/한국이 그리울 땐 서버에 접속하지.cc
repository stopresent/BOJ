#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
string ori_s, pre, suf, s;

void solve() {
	cin >> n >> ori_s;
	int pos = ori_s.find('*');
	pre = ori_s.substr(0, pos);
	suf = ori_s.substr(pos + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (pre.size() + suf.size() > s.size()) cout << "NE\n";
		else
		{
			if (s.substr(0, pre.size()) == pre && s.substr(s.size() - suf.size()) == suf) cout << "DA\n";
			else cout << "NE\n";
		}
	}
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}