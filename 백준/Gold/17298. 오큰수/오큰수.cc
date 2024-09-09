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
#include <stack>

using namespace std;

int n;
vector<int> v, ret;
stack<int> s;

void solve()
{
	cin >> n;
	v = vector<int>(1000005);
	ret = vector<int>(1000005, -1);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		while (s.size() && v[s.top()] < v[i])
		{
			ret[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ret[i] << " ";
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