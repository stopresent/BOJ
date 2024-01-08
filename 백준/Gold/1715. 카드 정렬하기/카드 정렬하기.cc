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

int n;
priority_queue<int, vector<int>, greater<int>> pq;
void solve()
{
	cin >> n;
	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		pq.push(temp);
	}

	if (pq.size() == 1)
	{
		cout << 0;
		return;
	}

	int cnt = 0;
	while (pq.size() != 1)
	{
		temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		pq.push(temp);
		cnt += temp;
	}

	cout << cnt;
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