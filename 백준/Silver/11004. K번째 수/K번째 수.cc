#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
priority_queue<int, vector<int>, greater<int>> pq;

void solve()
{
	cin >> n >> k;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		pq.push(temp);
	}

	for (int i = 0; i < k - 1; ++i)
		pq.pop();

	cout << pq.top();
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