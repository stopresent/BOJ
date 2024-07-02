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
	int k, n;
	cin >> k;
	for (int i = 1; i <= k; ++i)
	{
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> v[j];
		}

		sort(v.begin(), v.end(), greater<int>());
		int largest_gap = 0;
		for (int j = 0; j < n - 1; ++j)
		{
			largest_gap = max(largest_gap, v[j] - v[j + 1]);
		}

		cout << "Class " << i << '\n';
		cout << "Max " << v[0] << ", Min " << v[n - 1] << ", Largest gap " << largest_gap << '\n';
	}
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