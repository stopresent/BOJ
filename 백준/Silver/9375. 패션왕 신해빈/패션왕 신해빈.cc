#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <unordered_map>

using namespace std;

int t, n;

void solve()
{
	cin >> t;
	while (t-- > 0)
	{
		cin >> n;

		if (n == 0)
		{
			cout << 0 << '\n';
			continue;
		}

		string type, name;
		unordered_map<string, int> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> name >> type;
			m[type]++;
		}
		vector<int> ans(m.size());
		auto it = m.begin();
		int ret = 1;
		for (int i = 0; i < ans.size(); ++i)
		{
			ret *= (it->second + 1);
			//cout << it->second << '\n';
			it++;
		}
		//cout << endl;
		cout << ret - 1 << '\n';
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