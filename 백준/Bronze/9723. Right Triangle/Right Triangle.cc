#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	cin >> n;
	vector<int> v(3);
	for (int i = 0; i < n; i++)
	{
		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());
		if ((v[2] * v[2]) == ((v[0] * v[0]) + (v[1] * v[1])))
			cout << "Case #"<< i + 1 <<": YES" << '\n';
		else
			cout << "Case #" << i + 1 << ": NO" << '\n';
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