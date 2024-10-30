#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(100001);

// Find 함수: 경로 압축을 사용하여 부모 노드를 찾음
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// Union 함수: 두 집합을 합침
void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        parent[rootB] = rootA;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 부모 배열 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int cycleCount = 0;

    // 간선 입력 받기
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (find(u) == find(v)) {
            // 두 노드가 이미 같은 집합에 속해있다면 사이클 발생
            cycleCount++;
        } else {
            // 두 노드를 같은 집합으로 합침
            unionSet(u, v);
        }
    }

    // 연결 요소의 개수 계산
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            components++;
        }
    }

    // 결과 계산: 사이클의 개수 + (연결 요소의 개수 - 1)
    int result = cycleCount + (components - 1);
    cout << result << '\n';

    return 0;
}
