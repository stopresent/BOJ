#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	// 0의 개수는 2 * 5로 만들어짐

	int count2 = 0, count5 = 0;
	for (int i = 2; i <= n; ++i)
	{
		int temp = i;
		int j = 2;
		while (true)
		{
			if (temp == 1)
				break;

			if (temp % j == 0)
			{
				if (j == 2)
					count2++;
				if (j == 5)
					count5++;

				temp /= j;
			}
			else
			{
				j++;
			}
		}
	}

	if (count2 < count5)
		cout << count2;
	else
		cout << count5;
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