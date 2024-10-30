#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
int n, m;

bool findCycle(int node, int parent) {
    visited[node] = true;
    bool hasCycle = false;

    for (int next : graph[node]) {
        if (!visited[next]) {
            if (findCycle(next, node)) {
                hasCycle = true;
            }
        } else if (next != parent) {
            hasCycle = true;
        }
    }

    return hasCycle;
}

int main() {
    cin >> n >> m;

    // 그래프 입력 받기
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int components = 0;
    int cycleCount = 0;

    // 모든 노드에 대해 DFS 실행
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // 연결 요소의 시작점에서 사이클이 있는지 탐색
            if (findCycle(i, -1)) {
                cycleCount++;
            }
            components++;
        }
    }

    // 사이클을 제거하기 위해 필요한 간선 수 + 연결 요소를 하나로 만들기 위해 필요한 간선 수
    int result = (m - (n - components)) + (components - 1);
    cout << result << '\n';

    return 0;
}
