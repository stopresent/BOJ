#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

// 행복 점수

void solve()
{
	int happy_cnt = 0, sad_cnt = 0;
	char ch[10000] = "";
	cin.getline(ch, 10000);

	for (int i = 0; i < 10000; ++i)
	{
		if (ch[i] == 'H' || ch[i] == 'P' || ch[i] == 'Y')
			happy_cnt++;
		else if (ch[i] == 'S' || ch[i] == 'D')
			sad_cnt++;
		else if (ch[i] == 'A')
		{
			happy_cnt++;
			sad_cnt++;
		}
	}
	//double res = 50.00;

	if (happy_cnt == 0 && sad_cnt == 0)
	{
		double res = 50.00;
		cout << showpoint << setprecision(4) << res;
	}
	else
	{
		// 정수 연산으로만 풀기

		int temp = 0;

		temp = (happy_cnt * 100000) / (happy_cnt + sad_cnt);
		if (temp % 10 >= 5)
			temp += 10;
		temp /= 10;
		double res = temp * 0.01;
		cout << fixed;
		cout.precision(2);
		cout << res;
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