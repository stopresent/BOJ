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

int n;
int s1 = 0, s2 = 0;
vector<int> v(3000), v2(3000);

void solve()
{
	cin >> n;
	int t;
	string time;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		cin >> time;
		string ss1 = time.substr(0, 2);
		string ss2 = time.substr(3, 2);
		int temp = ((ss1[0] - '0') * 10 + (ss1[1] - '0')) * 60;
		int temp2 = (ss2[0] - '0') * 10 + (ss2[1] - '0');
		int st = temp + temp2;
		for (int j = st; j < 48 * 60; ++j)
		{
			if (t == 1)
				v[j]++;
			else
				v2[j]++;
		}
	}

	int total1 = 0, total2 = 0;
	for (int i = 0; i < 48 * 60; ++i)
	{
		if (v[i] > v2[i])
			total1++;
		else if (v[i] < v2[i])
			total2++;
	}

	int t1m = total1 / 60, t1s = total1 % 60;
	int t2m = total2 / 60, t2s = total2 % 60;

	cout.width(2); // 폭을 5로 지정
	cout.fill('0'); // 채움 문자는 '0'
	cout << t1m << ":";
	cout.width(2); // 폭을 5로 지정
	cout.fill('0'); // 채움 문자는 '0'
	cout << t1s << '\n';
	cout.width(2); // 폭을 5로 지정
	cout.fill('0'); // 채움 문자는 '0'
	cout << t2m << ":";
	cout.width(2); // 폭을 5로 지정
	cout.fill('0'); // 채움 문자는 '0'
	cout << t2s << '\n';
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