#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int switches[201];
int n;

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> switches[i];

	int temp = 0; // 학생의 수
	cin >> temp;
	int sex, num; // 성별과 받은 번호
	for (int i = 1; i <= temp; ++i)
	{
		cin >> sex >> num;

		if (sex == 1)
		{
			for (int j = num; j <= n; j += num)
			{
				if (switches[j] == 1)
					switches[j] = 0;
				else if (switches[j] == 0)
					switches[j] = 1;
			}
		}
		else if (sex == 2)
		{
			int pos1, pos2;
			pos1 = pos2 = num;

			if (switches[num] == 1)
				switches[num] = 0;
			else if (switches[num] == 0)
				switches[num] = 1;

			while (true)
			{
				pos1--;
				pos2++;

				if (pos1 < 1 || pos2 > n)
					break;
				if (switches[pos1] != switches[pos2])
					break;

				if (switches[pos1] == 1)
					switches[pos1] = 0;
				else if (switches[pos1] == 0)
					switches[pos1] = 1;

				if (switches[pos2] == 1)
					switches[pos2] = 0;
				else if (switches[pos2] == 0)
					switches[pos2] = 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << switches[i] << " ";
		if (i % 20 == 0)
			cout << '\n';
	}
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