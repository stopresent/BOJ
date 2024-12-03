#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int mx = 0, idx = 0;
	for (int i = 0; i < 5; ++i)
	{
		int sum = 0, temp;
		for (int j = 0; j < 4; ++j)
		{
			cin >> temp;
			sum += temp;
		}

		if (mx < sum)
		{
			mx = sum;
			idx = i + 1;
		}
	}

	cout << idx << " " << mx;
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