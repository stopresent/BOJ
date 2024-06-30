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
#include <map>

using namespace std;

int A, P;
vector<int> v;
map<int, int> m;

int digit_pow_p(int x)
{
	int ret = 0;

	while (x > 0)
	{
		int temp = x % 10;
		ret += pow(temp, P);
		x /= 10;
	}

	return ret;
}

void solve()
{
	cin >> A >> P;
	v.push_back(A);
	int temp = A, index = 0;

	m[A] = index++;
	while (true)
	{
		temp = digit_pow_p(temp);
		if (m.find(temp) != m.end())
		{
			cout << m[temp];
			break;
		}
		else
		{
 			m[temp] = index++;
		}
	}
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