#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve()
{
	vector<int> v(3);
	for (int i = 0; i < 3; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	cin >> s;
	for (int i = 0; i < 3; ++i)
	{
		if (s[i] == 'A')
			cout << v[0] << " ";
		else if (s[i] == 'B')
			cout << v[1] << " ";
		else
			cout << v[2] << " ";
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