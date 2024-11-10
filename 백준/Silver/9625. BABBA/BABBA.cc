#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int k;
string s;

void solve()
{
	cin >> k;
	int cnt1 = 1, cnt2 = 0;
	int temp1, temp2;
	for (int i = 0; i < k; ++i)
	{
		temp1 = cnt2;
		temp2 = cnt1 + cnt2;

		cnt1 = temp1;
		cnt2 = temp2;
	}

	cout << cnt1 << " " << cnt2;
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