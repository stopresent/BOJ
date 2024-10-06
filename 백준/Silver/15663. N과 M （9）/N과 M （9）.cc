#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
void solve()
{
	cin >> n >> m;
	v = vector<int>(n);
	for (int& x : v) cin >> x;
	sort(v.begin(), v.end());

	vector<int> temp = v;
	vector<int> prev(m);
	do {
		vector<int> v2(m);
		for (int i = 0; i < m; ++i)
			v2[i] = temp[i];
		if (v2 != prev)
		{
			for (int i = 0; i < m; ++i)
			{
				cout << temp[i] << " ";
			}
			cout << '\n';

			prev = v2;
		}

	} while (next_permutation(temp.begin(), temp.end()));
	temp.clear();
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