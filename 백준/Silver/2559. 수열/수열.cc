#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

void solve()
{
	cin >> n >> k;
	v = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int sum = 0, mx = 0;
	for (int i = 0; i < k; i++)
	{
		sum += v[i];
	}
	mx = sum;

	for (int i = k; i < n; i++)
	{
		sum += v[i];
		sum -= v[i - k];
		mx = max(mx, sum);
	}

	cout << mx;
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