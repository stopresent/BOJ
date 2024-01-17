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

N : 1 ANS : 0

N : 2 ANS : 3
3

N : 3 ANS : 0

N : 4 ANS : 11
3*3 + 2

N : 5 ANS : 0

N : 6 ANS : 41
3*3*3 + 3*2*2 + 2
27 + 12 + 2

N : 7 ANS : 0

N : 8 ANS : 153
3*3*3*3 + 3*3*3*2 + 3*2*2 + 2*2 + 2

N : 9 ANS : 0

N : 10 ANS : 571

N : 30 ANS : 299303201

*/

int n;
int cache[40];
void solve()
{
	cin >> n;
	cache[0] = 1;
	cache[1] = 0;
	cache[2] = 3;
	cache[3] = 0;
	//cache[4] = 11;


	for (int i = 4; i <= n; ++i)
	{
		cache[i] = cache[i - 2] * cache[2];
		for (int j = i - 4; j >= 0; j = j - 2)
		{
			cache[i] += cache[j] * 2;
		}
	}

	cout << cache[n];
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