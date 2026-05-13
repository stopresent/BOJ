#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    const int MOD = 1000000007;
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int coin : money)
    {
        for (int amount = coin; amount <= n; amount++)
        {
            dp[amount] += dp[amount - coin];
            if (dp[amount] >= MOD) dp[amount] -= MOD;
        }
    }
    
    return dp[n];
}