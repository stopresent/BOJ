#include <bits/stdc++.h>
using namespace std;

int main(){
    // 빠른 입출력 설정
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 네 개의 깊이 읽기 값을 저장할 배열
    int depths[4];
    for(int i=0; i<4; i++) {
        cin >> depths[i];
    }
    
    // 모든 값이 동일한지 확인
    bool all_same = true;
    for(int i=1; i<4; i++) {
        if(depths[i] != depths[0]){
            all_same = false;
            break;
        }
    }
    
    if(all_same){
        cout << "Fish At Constant Depth";
        return 0;
    }
    
    // 엄격하게 증가하는지 확인
    bool strictly_increasing = true;
    for(int i=1; i<4; i++) {
        if(depths[i] <= depths[i-1]){
            strictly_increasing = false;
            break;
        }
    }
    
    if(strictly_increasing){
        cout << "Fish Rising";
        return 0;
    }
    
    // 엄격하게 감소하는지 확인
    bool strictly_decreasing = true;
    for(int i=1; i<4; i++) {
        if(depths[i] >= depths[i-1]){
            strictly_decreasing = false;
            break;
        }
    }
    
    if(strictly_decreasing){
        cout << "Fish Diving";
        return 0;
    }
    
    // 위의 어떤 조건도 만족하지 않으면 "No Fish" 출력
    cout << "No Fish";
}
