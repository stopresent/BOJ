#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> um;
void solve()
{
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		um[s]++;
	}

	int mx = 0;
	string ret = "";
	auto it = um.begin();
	for (auto it = um.begin(); it != um.end(); ++it)
	{
		if (it->second > mx)
		{
			mx = it->second;
			ret = it->first;
		}
		else if (it->second == mx)
		{
			if (ret > it->first)
			{
				ret = it->first;
			}
		}
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