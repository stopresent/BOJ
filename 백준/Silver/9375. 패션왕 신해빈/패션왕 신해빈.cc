#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int T, n;

void solve()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		int ret = 1;
		string clothes, type;
		map<string, int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> clothes >> type;
			m[type]++;
		}

		// m 전체 순회하기
		for (const auto& [key, value] : m)
		{
			ret *= (value + 1);
		}

		cout << ret - 1 << '\n';
	}
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