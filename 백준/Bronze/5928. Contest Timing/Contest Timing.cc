#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int D, H, M;
    cin >> D >> H >> M;
    
    // 기준 시간: 11월 11일 00시 00분
    // 시작 시간: 11월 11일 11시 11분 = 11*60 + 11 = 671분
    const int start_time = 11 * 60 + 11; // 671분
    
    // 종료 시간 계산
    // 각 날은 1440분 (24*60)으로 계산
    int end_time = (D - 11) * 1440 + H * 60 + M;
    
    // 총 소요 시간
    int total_time = end_time - start_time;
    
    if(total_time >= 0){
        cout << total_time;
    }
    else{
        cout << "-1";
    }
    
    return 0;
}
