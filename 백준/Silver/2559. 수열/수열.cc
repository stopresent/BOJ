#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, k, ret = -10000, psum[100004], temp;

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}
	for (int i = k; i <= n; i++)
	{
		ret = max(ret, psum[i] - psum[i - k]);
	}

	cout << ret;
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}