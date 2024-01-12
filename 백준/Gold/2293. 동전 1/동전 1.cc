#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int dp[20000];
vector<int> arr;
void solve()
{
	cin >> n >> k;
	arr = vector<int>(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	dp[0] = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = arr[i]; j <= k; ++j)
		{
			dp[j] += dp[j - arr[i]];
			//cout << "j : " << j << " dp[" << j << "] : " << dp[j] << endl;
		}
	}

	cout << dp[k];
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