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

using namespace std;

void solve()
{
	int n;
	cin >> n;
	int ret = 1;
	for (int i = n - 1; i > 0;)
	{
		int sum = i;
		for (int j = i - 1; j > 0; --j)
		{
			sum += j;
			if (sum == n)
			{
				ret++;
				break;
			}
			else if (sum > n)
			{
				break;
			}
			else if (sum < n)
			{

			}
		}

		//cout << "Sum : " << sum << endl;

		i--;
	}

	cout << ret;
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