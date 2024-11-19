#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	cin >> n;
	int ret = 0, temp;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
	{
		ret = max(ret, v[i] + i + 1);
	}
	cout << ret + 1;
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}