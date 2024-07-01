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

void solve()
{
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	int max_incre_len = 1, incre_len = 1, max_decre_len = 1, decre_len = 1;

	for (int i = 0; i < N - 1; ++i)
	{
		if (v[i] == v[i + 1])
		{
			incre_len++;
			max_incre_len = max(max_incre_len, incre_len);
			decre_len++;
			max_decre_len = max(max_decre_len, decre_len);
		}
		else if (v[i] < v[i + 1])
		{
			decre_len = 1;
			incre_len++;
			max_incre_len = max(max_incre_len, incre_len);
		}
		else
		{
			incre_len = 1;
			decre_len++;
			max_decre_len = max(max_decre_len, decre_len);
		}
	}

	int ret = max(max_incre_len, max_decre_len);
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