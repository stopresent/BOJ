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

using namespace std;

int N, M, J;

void solve()
{
	cin >> N >> M >> J;
	pair<int, int> cur{1, M};
	int ret = 0;

	for (int i = 0; i < J; ++i)
	{
		int pos;
		cin >> pos;
		
		if (pos <= cur.second && pos >= cur.first)
		{
			continue;
		}
		else if (pos < cur.first)
		{
			int temp = cur.first - pos;
			ret += temp;
			cur.first -= temp;
			cur.second -= temp;
		}
		else if (pos > cur.second)
		{
			int temp = pos - cur.second;
			ret += temp;
			cur.first += temp;
			cur.second += temp;
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