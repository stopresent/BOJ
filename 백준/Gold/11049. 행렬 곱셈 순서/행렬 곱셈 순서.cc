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
    int N;
    cin >> N;

    vector<int> dimensions(N + 1);
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) 
    {
        int r, c;
        cin >> r >> c;
        dimensions[i] = r;
        if (i == N - 1) 
        {
            dimensions[i + 1] = c;
        }
    }

    for (int length = 2; length <= N; ++length) 
    {
        for (int i = 0; i <= N - length; ++i) 
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) 
            {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][N - 1] << endl;
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