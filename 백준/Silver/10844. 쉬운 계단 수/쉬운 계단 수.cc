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

const int MOD = 1000000000;
int dp[101][10];
int n;

void solve()
{
    cin >> n;

    for (int i = 1; i < 10; i++) 
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            if (j == 0)
                dp[i][0] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][9] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] %= MOD;
        }
    }

    int ret = 0;
    for (int i = 0; i < 10; i++) 
    {
        ret = (ret + dp[n][i]) % MOD;
    }

    cout << ret << "\n";
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