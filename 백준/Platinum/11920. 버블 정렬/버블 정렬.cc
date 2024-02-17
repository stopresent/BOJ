#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int n, k;
vector<int> v;
priority_queue<int, vector<int>, greater<int>> q;
void solve()
{
	cin >> n >> k;
	v = vector<int>(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < k; ++i)
	{
		q.push(v[i]);
	}

	for (int i = 0; i < n - k; ++i)
	{
		q.push(v[i + k]);
		v[i] = q.top();
		q.pop();
	}

	for (int i = 0; i < n - k; ++i)
		cout << v[i] << " ";

	while (q.empty() == false)
	{
		cout << q.top() << " ";
		q.pop();
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