#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
void solve()
{
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return;
	}

	vector<int> v;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	float f = n * 0.15;
	if ((f - (int)f) >= 0.5)
		f = (int)f + 1;
	else
		f = (int)f;

	int sum = 0, idx = 0;
	for (int i = f; i < n - f; ++i)
	{
		sum += v[i];
		idx++;
	}
	float ave = sum / (float)idx;
	if ((ave - (int)ave) >= 0.5)
		ave = (int)ave + 1;
	else
		ave = (int)ave;

	cout << ave;
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