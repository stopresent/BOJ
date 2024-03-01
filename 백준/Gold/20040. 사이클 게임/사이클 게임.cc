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
int n, m, cnt = 1;
int unf[1000000];
bool flag = false;

int Find(int v)
{
	if (v == unf[v])
		return v;
	return unf[v] = Find(unf[v]);
}

void Merge(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		if (a < b)
			unf[a] = b;
		else
			unf[b] = a;
	}
	else // 대장이 같은 경우
	{
		// 사이클이 발생했다
		flag = true;
	}
}

void solve()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		unf[i] = i;

	int v1, v2;
	for (int i = 1; i <= m; ++i)
	{
		cin >> v1 >> v2;
		// v1과 v2가 연결됨
		Merge(v1, v2);
		if (flag == false)
			cnt++;
	}

	if (flag == false)
		cout << 0;
	else
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