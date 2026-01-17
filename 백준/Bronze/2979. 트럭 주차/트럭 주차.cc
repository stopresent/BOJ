#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int A, B, C;
vector<int> cnt(101);
int ret = 0;

void solve()
{
	cin >> A >> B >> C;
	int a, b;
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b;
		for (int j = a; j < b; j++)
			cnt[j]++;
	}

	for (int i = 0; i < 101; i++)
	{
		if (cnt[i] == 1)
			ret += A;
		else if (cnt[i] == 2)
			ret += 2 * B;
		else if (cnt[i] == 3)
			ret += 3 * C;
	}

	cout << ret;
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