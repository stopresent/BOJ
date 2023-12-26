#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct country
{
	int idx;
	int gold;
	int silver;
	int bronze;
};

vector<country> vec;

int n, k;
void solve()
{
	cin >> n >> k;
	vec = vector<country>(n + 1);
	int idx, g, s, b, pos = 0, res = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i].idx >> vec[i].gold >> vec[i].silver >> vec[i].bronze;
		if (vec[i].idx == k)
			pos = i;
	}

	for (int i = 0; i < n; ++i)
	{
		if (vec[i].gold > vec[pos].gold)
		{
			res++;
		}
		else if (vec[i].gold == vec[pos].gold && vec[i].silver > vec[pos].silver)
		{
			res++;
		}
		else if (vec[i].gold == vec[pos].gold && vec[i].silver == vec[pos].silver && vec[i].bronze > vec[pos].bronze)
		{
			res++;
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

	solve();

	return 0;
}