#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool hasPossibility(int input, int number, int strike, int ball)
{
	int input100 = input / 100;
	int input10 = input / 10 % 10;
	int input1 = input % 10;
	int number100 = number / 100;
	int number10 = number / 10 % 10;
	int number1 = number % 10;

	if (input100 == input10 || input100 == input1 || input10 == input1)
		return false;
	if (input100 == 0 || input10 == 0 || input1 == 0)
		return false;

	int checkStrike = 0, checkBall = 0;
	if (input100 == number100)
	{
		checkStrike++;
	}
	if (input10 == number10)
	{
		checkStrike++;
	}
	if (input1 == number1)
	{
		checkStrike++;
	}

	if (input100 == number10 || input100 == number1)
	{
		checkBall++;
	}
	if (input10 == number1)
	{
		checkBall++;
	}
	if (number100 == input10 || number100 == input1)
	{
		checkBall++;
	}
	if (number10 == input1)
	{
		checkBall++;
	}

	if (checkStrike == strike && checkBall == ball)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int n, res = 0, number, strike, ball, maxNum = 0;
vector<int> vec;
void solve()
{
	vec = vector<int>(1000);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> number >> strike >> ball;
		for (int j = 123; j < 1000; ++j)
		{
			if (hasPossibility(j, number, strike, ball))
			{
				vec[j]++;
				maxNum = max(maxNum, vec[j]);
			}
			else
			{
				vec[j] = -100;
			}
		}
	}

	for (int i = 123; i < 1000; ++i)
	{
		if (vec[i] == maxNum)
		{
			res++;
			//cout << i << endl;
		}
	}

	if (maxNum == 0)
		cout << 0;
	else
		cout << res;
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