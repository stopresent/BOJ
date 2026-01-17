#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve() {
	cin >> t;
	while (t--) {
		cin >> n;
		int cnt2 = 0, cnt5 = 0;
		for (int i = 2; i <= n; i *= 2)
			cnt2 += n / i;
		for (int i = 5; i <= n; i *= 5)
			cnt5 += n / i;
		cout << min(cnt2, cnt5) << '\n';
	}
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}