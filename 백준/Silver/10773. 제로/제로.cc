#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int k, ret;

void solve()
{
	cin >> k;
	vector<int> v;
	int temp;
	for (int i = 0; i < k; ++i)
	{
		cin >> temp;
		if (temp == 0)
			v.pop_back();
		else
			v.push_back(temp);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		ret += v[i];
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