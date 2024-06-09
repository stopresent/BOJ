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

int longestCommonSubstring(string s1, string s2) 
{
    int m = s1.length();
    int n = s2.length();

    // DP 테이블 초기화
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int max_length = 0; // 가장 긴 공통 부분 문자열의 길이

    for (int i = 1; i <= m; ++i) 
    {
        for (int j = 1; j <= n; ++j) 
        {
            if (s1[i - 1] == s2[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_length = max(max_length, dp[i][j]);
            }
            // 연속하지 않은 경우 0으로 초기화
            else 
            {
                dp[i][j] = 0;
            }
        }
    }

    return max_length;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2; // 입력

    // 결과 출력
    cout << longestCommonSubstring(s1, s2) << endl;
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