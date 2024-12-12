#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	vector<string> v2 = v;
	sort(v.begin(), v.end());
	if (v2 == v)
	{
		cout << "INCREASING";
		return;
	}
	reverse(v.begin(), v.end());
	if (v2 == v)
	{
		cout << "DECREASING";
	}
	else
	{
		cout << "NEITHER";

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