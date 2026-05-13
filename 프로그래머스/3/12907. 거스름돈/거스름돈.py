def solution(n, money):
    MOD = 1_000_000_007
    dp = [0] * (n + 1)
    dp[0] = 1
    
    for coin in money:
        for amount in range(coin, n + 1):
            dp[amount] = (dp[amount] + dp[amount - coin]) % MOD
    
    return dp[n]