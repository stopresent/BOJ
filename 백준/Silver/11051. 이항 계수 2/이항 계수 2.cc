#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    // 2차원 DP 테이블 초기화
    // dp[n][k] = C(n, k)
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    
    for(int n = 0; n <= N; n++){
        for(int k = 0; k <= min(n, K); k++){
            if(k == 0 || k == n){
                dp[n][k] = 1;
            }
            else{
                dp[n][k] = (dp[n-1][k-1] + dp[n-1][k]) % MOD;
            }
        }
    }
    
    cout << dp[N][K];
    
    return 0;
}
