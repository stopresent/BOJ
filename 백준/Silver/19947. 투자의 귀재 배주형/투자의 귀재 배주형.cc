#include<bits/stdc++.h>
using namespace std;
int dp[11];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int h, y;
	cin >> h >> y;
	dp[0] = h;
    for (int i =1; i <= y; i++)
    {
        dp[i] = (int)(dp[i - 1] * 1.05);
        if (i >= 3)
        {
            dp[i] = max(dp[i],(int)(dp[i-3]* 1.2));
        }
        if (i >= 5)
        {
            dp[i] = max((int)dp[i], (int)(dp[i - 5] * 1.35));
        }
    }
	cout << dp[y];
}