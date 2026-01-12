#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string str;

void solve()
{
	cin >> str;
	int sum = 0;
	bool isAdd = false;
	for (int i = 0; i < str.size(); i++)
	{
		bool isEven = i % 2;

		if (str[i] == '*')
		{
			isAdd = isEven;
		}
		else
		{
			sum += (str[i] - '0') * (isEven ? 3 : 1);
		}
	}

	sum %= 10;

	if (isAdd)
	{
		for (int i = 0; i < 10; ++i)
		{
			if ((sum + i * 3) % 10 == 0)
			{
				cout << i;
				break;
			}
		}
	}
	else
	{
		cout << (10 - sum) % 10;
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