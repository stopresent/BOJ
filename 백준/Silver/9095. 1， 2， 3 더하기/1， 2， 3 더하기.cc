#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*

정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

0 < n < 11

*/

// 딱 봤을땐 동적계획법같은뎅

int t, n;
vector<int> cache(11);

void solve()
{
	cin >> t;

	// 여기서 캐시를 채워넣기

	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;

	for (int i = 4; i <= 10; ++i)
	{
		cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
	}

	for (int i = 0; i < t; ++i)
	{
		cin >> n;

		cout << cache[n] << endl;
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