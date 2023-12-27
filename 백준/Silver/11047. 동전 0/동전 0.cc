#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> vec;
void setting()
{
	cin >> n >> k;

	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	reverse(vec.begin(), vec.end());
}

int res = 0;
void solve()
{
	int i = 0;
	int temp = k;
	while (k != 0)
	{
		if ((temp /= vec[i]) != 0)
		{
			temp = k;
			res += (temp / vec[i]);
			k %= vec[i];
		}
		else
		{
			temp = k;
			i++;
		}
	}

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