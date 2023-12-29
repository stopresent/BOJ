#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string str;
int numbers[51];
string signs[51];

int p1 = 0, p2 = 0, res = 0;
// -가 나오면 다음 -가 나올 때까지 그 사이는 다 더해주고 빼기

void setting()
{
	cin >> str;

	int temp = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] != '+' && str[i] != '-')
		{
			temp *= 10;
			temp += str[i] - '0';
		}
		else
		{
			numbers[p1] = temp;
			p1++;
			signs[p2] = str[i];
			p2++;

			temp = 0;
		}
	}
	numbers[p1] = temp;
}

void solve()
{
	int pos = 0, pos2 = 0;
	res = numbers[pos];
	while (true)
	{
		if (signs[pos2] == "-")
		{
			pos2++;

			int temp = 0;
			while (signs[pos2] != "-" && pos2 < p2)
			{
				pos++;
				temp += numbers[pos];
				pos2++;
			}
			pos++;
			temp += numbers[pos];
			res -= temp;
		}
		else if (signs[pos2] == "+")
		{
			pos++;
			pos2++;
			res += numbers[pos];
		}

		if (pos == p1)
			break;
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