#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<vector<int>> v;
string s;

void solve() {
	cin >> h >> w;
	v = vector<vector<int>>(h + 1, vector<int>(w + 1, 0));
	for (int y = 0; y < h; y++) {
		cin >> s;
		for (int x = 0; x < w; x++) {
			if (s[x] == '.') v[y][x] = -1;
		}
	}

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (v[y][x] == 0) {
				int cnt = 1;
				while (v[y][x + 1] == -1) {
					v[y][x + 1] = cnt++;
					x++;
				}
			}
		}
	}

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) cout << v[y][x] << ' ';
		cout << '\n';
	}
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}