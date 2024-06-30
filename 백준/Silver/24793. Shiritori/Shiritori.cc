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
#include <unordered_map>
#include <map>

using namespace std;

void solve()
{
	int N;
	cin >> N;
	string str, pre_str;
	map<string, int> m;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		if (i == 0)
		{
			m[str]++;
			pre_str = str;
			continue;
		}

		m[str]++;
		if (m[str] >= 2)
		{
			if (i % 2 == 0) // player 1
			{
				cout << "Player 1 lost";
				return;
			}
			else // player 2
			{
				cout << "Player 2 lost";
				return;
			}
		}

		int pre_size = pre_str.size();
		if (str[0] != pre_str[pre_size - 1])
		{
			if (i % 2 == 0) // player 1
			{
				cout << "Player 1 lost";
				return;
			}
			else // player 2
			{
				cout << "Player 2 lost";
				return;
			}
		}

		pre_str = str;
	}

	cout << "Fair Game";
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