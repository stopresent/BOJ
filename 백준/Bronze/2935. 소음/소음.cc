#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string a, b, sim, ret;

void solve()
{
	cin >> a >> sim >> b;

	if (sim == "*")
	{
		for (int i = 0; i < b.size() - 1; ++i)
		{
			a += '0';
		}

		ret = a;
	}
	else if (sim == "+")
	{
		if (a.size() < b.size())
			swap(a, b);
		
		if (a.size() == b.size())
		{
			ret = "2";
			for (int i = 0; i < a.size() - 1; ++i)
			{
				ret += '0';
			}
		}
		else
		{
			int size = a.size() - b.size() - 1;
			ret = "1";
			for (int i = 0; i < size; ++i)
				ret += '0';
			ret += b;
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