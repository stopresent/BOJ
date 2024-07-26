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

string digitSum(string str)
{
	int sum = 0;
	
	for (int i = 0; i < str.size(); ++i)
	{
		sum += str[i] - '0';
	}

	string ret = "";
	while (sum > 0)
	{
		ret += sum % 10 + '0';
		sum /= 10;
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

void solve()
{
	string num;
	cin >> num;

	int ret = 0;
	while (num.size() > 1)
	{
		num = digitSum(num);
		ret++;
	}

	cout << ret << '\n';
	if (num == "3" || num == "6" || num == "9")
		cout << "YES";
	else
		cout << "NO";
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