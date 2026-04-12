#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool corect(string input, string front, string back)
{
	if (front.size() + back.size() > input.size()) return false;
	if (input.substr(0, front.size()) == front && input.substr(input.size() - back.size()) == back) return true;

	return false;
}

void solve() {
	cin >> n >> s;
	int idx = s.find('*');
	string front, back;
	front = s.substr(0, idx);
	back = s.substr(idx + 1);
	string a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (corect(a, front, back)) cout << "DA\n";
		else cout << "NE\n";
	}
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}