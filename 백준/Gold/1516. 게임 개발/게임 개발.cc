//백준1516 게임 개발                                                        
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main() {
    /*입력*/
    int N;
    cin >> N;
    
    vector<int> v[501];
    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;
        while (input != -1) {
            v[i].push_back(input);
            cin >> input;
        }
    }
 
    /*각 건물을 짓는데 걸리는 시간*/
    int time[501];
    for (int i = 1; i <= N; i++) {
        time[i] = v[i][0];
    }
 
    /*위상 정렬*/
    vector<int> adj[501];
    int inDeg[501] = { 0, };
    queue<int> q;
    int result[501]; //출력배열 - 각 건물이 완성되기까지 걸리는 최소 시간
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < v[i].size(); j++) {
            adj[v[i][j]].push_back(i);
            inDeg[i]++;
        }
    }
 
    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
        result[i] = time[i];
    }
 
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
 
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            inDeg[next]--;
            
            result[next] = max(result[next], result[cur] + time[next]); //★
 
            if (inDeg[next] == 0) {
                q.push(next);
            }
        }
    }
 
    /*출력*/
    for (int i = 1; i <= N; i++) {
        cout << result[i] << endl;
    }
 
    return 0;
}
