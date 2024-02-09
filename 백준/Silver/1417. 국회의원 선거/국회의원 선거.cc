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
int n, res = 0;
priority_queue<int> pq;
void solve()
{
	cin >> n;

	int dasom;
	cin >> dasom;

	for (int i = 1; i < n; ++i)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	while (true)
	{
		if (pq.empty())
			break;

		if (pq.top() < dasom)
			break;

		int t = pq.top() - 1;
		pq.pop();
		pq.push(t);
		dasom++;
		res++;
	}

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