#include <bits/stdc++.h>
using namespace std;

// 확장 유클리드 알고리즘을 사용하여 a와 b의 최대공약수와 x, y를 반환
long long extended_gcd_func(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_gcd_func(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

// a의 모듈러 m에 대한 역원을 반환. 존재하지 않으면 -1 반환
long long mod_inverse(long long a, long long m) {
    long long x, y;
    long long d = extended_gcd_func(a, m, x, y);
    if (d != 1)
        return -1; // 역원이 존재하지 않음
    else {
        long long res = (x % m + m) % m;
        return res;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while(T--){
        long long M, N, x, y;
        cin >> M >> N >> x >> y;
        
        // 최대공약수 계산
        long long d, a, b;
        d = extended_gcd_func(M, N, a, b);
        
        // 해가 존재하는지 확인
        if( (y - x) % d != 0 ){
            cout << "-1\n";
            continue;
        }
        
        // LCM 계산
        long long lcm = (M / d) * N;
        
        // 계수 계산
        long long k = x;
        // M*t ≡ (y - x) mod N
        // t ≡ (y -x)/d * inv(M/d) mod (N/d)
        long long M_d = M / d;
        long long N_d = N / d;
        long long rhs = (y - x) / d;
        
        // M_d과 N_d는 서로소
        long long inv = mod_inverse(M_d, N_d);
        if(inv == -1){
            // 역원이 존재하지 않으므로 해가 없음
            cout << "-1\n";
            continue;
        }
        
        long long t = (rhs * inv) % N_d;
        if(t < 0) t += N_d;
        
        k = x + M * t;
        
        // k이 1 이상이고 lcm 이하인지 확인
        if(k <= lcm && k >=1){
            cout << k << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
    
    return 0;
}
