#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 입력 받기
    int N;
    cin >> N;
    
    // 과일 배열 S
    vector<int> S(N);
    for(int &x : S) cin >> x;
    
    // 과일 종류별 빈도수 저장 (과일 종류는 1~9)
    int freq[10] = {0};
    int unique_count = 0;
    
    int left = 0;
    int max_length = 0;
    
    // 슬라이딩 윈도우 적용
    for(int right = 0; right < N; right++){
        // 현재 과일의 빈도 증가
        if(freq[S[right]] == 0){
            unique_count++;
        }
        freq[S[right]]++;
        
        // 과일 종류가 2를 초과하면 왼쪽 포인터 이동
        while(unique_count > 2){
            freq[S[left]]--;
            if(freq[S[left]] == 0){
                unique_count--;
            }
            left++;
        }
        
        // 현재 윈도우의 크기 업데이트
        max_length = max(max_length, right - left + 1);
    }
    
    // 결과 출력
    cout << max_length;
    
    return 0;
}
