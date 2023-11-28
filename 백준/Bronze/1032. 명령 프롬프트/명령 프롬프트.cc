#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<string> strs(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> strs[i];
	}

	char ret[50];
	for (int i = 0; i < strs[0].length(); i++)
	{
		bool flag = false;
		char temp = strs[0][i];
		for (int j = 1; j < n; ++j)
		{
			if (temp != strs[j][i])
			{
				flag = true;
				break;
			}
		}

		if (flag)
			ret[i] = '?';
		else
			ret[i] = temp;
	}

	for (int i = 0; i < strs[0].length(); i++)
		cout << ret[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();
}
