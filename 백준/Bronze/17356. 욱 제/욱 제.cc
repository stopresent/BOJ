#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B;
    cin >> A >> B;
    
    double M = static_cast<double>(B - A) / 400.0;
    double probability = 1.0 / (1.0 + pow(10.0, M));
    
    // 출력 시 소수점 이하 10자리까지 표시
    cout << fixed << setprecision(10) << probability;
    
    return 0;
}
