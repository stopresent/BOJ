#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s;
int arr[30];
void solve() {
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		arr[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}