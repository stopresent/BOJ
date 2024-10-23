#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> dp1(100); // 0으로 끝나는거 수
vector<long long> dp2(100); // 1로 끝나는거 수

void solve()
{
	cin >> n;

	dp1[1] = 0;
	dp1[2] = 1;
	dp2[1] = 1;
	dp2[2] = 0;
	for (int i = 3; i <= n; ++i)
	{
		dp1[i] = dp1[i - 1] + dp2[i - 1];
		dp2[i] = dp1[i - 1];
	}

	cout << dp1[n] + dp2[n];
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