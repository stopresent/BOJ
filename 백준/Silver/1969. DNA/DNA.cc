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

int N, M;
int HammingDistance = 0;
vector<string> v;
int ch[] = { 0, 0, 0, 0 };

void clear_ch()
{
	for (int i = 0; i < 4; ++i)
		ch[i] = 0;
}

void check(char c)
{
	if (c == 'A')
		ch[0]++;
	else if (c == 'C')
		ch[1]++;
	else if (c == 'G')
		ch[2]++;
	else if (c == 'T')
		ch[3]++;
}

int get_max_ch_index()
{
	int ret = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (ch[ret] < ch[i + 1])
		{
			ret = i + 1;
		}
	}

	return ret;
}

char get_max_ch(int index)
{
	if (index == 0)
		return 'A';
	else if (index == 1)
		return 'C';
	else if (index == 2)
		return 'G';
	else if (index == 3)
		return 'T';
}

void solve()
{
	cin >> N >> M;
	v = vector<string>(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	string ret = "";
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			check(v[j][i]);
		}

		int index = get_max_ch_index();
		char c = get_max_ch(index);
		ret += c;
		for (int j = 0; j < N; ++j)
		{
			if (v[j][i] != c)
				HammingDistance++;
		}

		clear_ch();
	}

	cout << ret << '\n';
	cout << HammingDistance;
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