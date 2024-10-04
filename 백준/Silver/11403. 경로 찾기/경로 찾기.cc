#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    // 인접 행렬 입력 받기
    vector<vector<int>> adj(N, vector<int>(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> adj[i][j];
        }
    }
    
    // 도달 가능성 행렬 초기화 (복사)
    vector<vector<int>> reach = adj;
    
    // 플로이드-워셜 알고리즘 적용
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(reach[i][k] && reach[k][j]){
                    reach[i][j] = 1;
                }
            }
        }
    }
    
    // 결과 출력
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << reach[i][j];
            if(j != N-1){
                cout << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}
