#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// R은 뒤집기
// D는 맨 위 버리기

int t, pos = 0, rpos = 0;
bool errorFlag = false;

void solve()
{
	cin >> t;

	while (t > 0)
	{
		string str;
		cin >> str;

		int vsize;
		cin >> vsize;

		string vstr;
		cin >> vstr;

		vector<int> vec(vsize);
		int vpos = 0, temp = 0;
		for (int i = 1; i < vstr.size(); ++i)
		{
			if (vec.size() == 0)
				break;

			if (vstr[i] == ',' || vstr[i] == ']')
			{
				vec[vpos] = temp;
				vpos++;
				temp = 0;
			}
			else
			{
				temp *= 10;
				temp += vstr[i] - '0';
			}
		}

		bool rflag = false;
		pos = 0, errorFlag = false, rpos = vec.size() - 1;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == 'R')
			{
				if (rflag == false)
					rflag = true;
				else
					rflag = false;
				//R(vec);
			}
			if (str[i] == 'D')
			{
				if (rflag == false)
				{
					pos++;
					if (pos > rpos + 1)
					{
						errorFlag = true;
					}
				}
				else
				{
					rpos--;
					if (rpos + 1< pos)
					{
						errorFlag = true;
					}
				}
				//D(vec);
			}

			if (errorFlag == true)
			{
				cout << "error" << '\n';
				break;
			}
		}

		if (errorFlag == true)
		{
			t--;
			continue;
		}

		cout << "[";

		if (vec.size() == 0 || pos > rpos)
		{
			cout << "]" << '\n';
		}
		else if (rflag == false)
		{
			for (int i = pos; i < rpos; ++i)
			{
				cout << vec[i] << ",";
			}

			cout << vec[rpos] << "]" << '\n';
		}
		else if (rflag == true)
		{
			for (int i = rpos; i > pos; --i)
			{
				cout << vec[i] << ",";
			}

			cout << vec[pos] << "]" << '\n';
		}

		t--;
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