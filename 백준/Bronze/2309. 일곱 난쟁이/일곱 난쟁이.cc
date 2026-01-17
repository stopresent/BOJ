#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> v(9);

void solve()
{
	for (int i = 0; i < 9; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	do
	{
		int sum = 0;
		for (int i = 0; i < 7; i++)
			sum += v[i];
		if (sum == 100) break;
	} while (next_permutation(v.begin(), v.begin() + 9));

	for (int i = 0; i < 7; i++)
		cout << v[i] << '\n';
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