#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int num, n, digit = 0, cur = 100, res = 123456789;
vector<int> broken;
void setting()
{
	cin >> num >> n;
	broken = vector<int>(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> broken[i];
	}

	int temp = num;
	while (temp > 0)
	{
		digit++;
		temp /= 10;
	}

	if (num == 0)
		digit = 1;
}

void DFS(int L, int ret)
{
	if (L > digit + 1)
		return;

	if (L == digit || L == digit - 1 || L == digit + 1)
	{
		if (L != 0)
		{
			int dis = abs(ret - num);
			int temp = dis + L;
			//cout << "ret : " << ret << endl;
			res = min(res, temp);
			//cout << "res : " << res << endl;

			if (digit == 1 && ret == 0 && num == 0)
				res = 1;
		}
	}


	for (int i = 0; i <= 9; ++i)
	{
		bool flag = true;
		for (int j = 0; j < broken.size(); ++j)
		{
			if (i == broken[j])
			{
				flag = false;
				break;
			}
		}

		if (flag == true)
		{
			DFS(L + 1, ret * 10 + i);
		}
	}
}

void solve()
{
	DFS(0, 0);

	int temp = abs(num - cur);
	res = min(res, temp);

	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	solve();

	return 0;
}