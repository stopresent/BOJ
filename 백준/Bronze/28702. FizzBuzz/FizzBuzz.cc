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
#include <string>

using namespace std;

bool flag = false;
string s;
string a[] = { "FizzBuzz", "Fizz", "Buzz" };
int ret;
void solve()
{
	for (int i = 0; i < 3; ++i)
	{
		cin >> s;

		if (!flag)
			if (s != "FizzBuzz" && s != "Fizz" && s != "Buzz")
			{
				flag = true;
				ret = stoi(s) + (3 - i);
			}
	}

	if (ret % 3 == 0 && ret % 5 == 0)
		cout << "FizzBuzz";
	else if (ret % 3 == 0)
		cout << "Fizz";
	else if (ret % 5 == 0)
		cout << "Buzz";
	else
		cout << ret;
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