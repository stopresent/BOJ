#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C, ch[20], cnt = 0;
char moem[] = { 'a', 'e', 'i', 'o', 'u' };
string str;
char resp[100];
void DFS(int s, int l)
{
	if (l == L)
	{
		bool flag = false;
		bool isMoem = false;
		int a = 0, b = 0;
		for (int j = 0; j < l; ++j)
		{
			isMoem = false;
			for (int k = 0; k < sizeof(moem); ++k)
			{
				if (a >= 1 && b >= 2)
				{
					flag = true;
					break;
				}
				if (str[ch[j]] == moem[k])
				{
					a++;
					isMoem = true;

					break;
				}
			}

			if (isMoem == false)
			{
				b++;
			}

			if (a >= 1 && b >= 2)
			{
				flag = true;
				break;
			}
		}

		if (flag == true)
		{
			for (int j = 0; j < l; ++j)
			{
				cout << str[ch[j]];
			}
			cout << endl;
			cnt++;

		}

	}
	else
	{
		for (int i = s; i < C; ++i)
		{
			ch[l] = i;
			DFS(i + 1, l + 1);
		}
	}
}

void solve()
{
	cin >> L >> C;
	for (int i = 0; i < C; ++i)
	{
		char input;
		cin >> input;
		str += input;
	}

	sort(str.begin(), str.end());

	DFS(0, 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();
	//cout << cnt;

	return 0;
}