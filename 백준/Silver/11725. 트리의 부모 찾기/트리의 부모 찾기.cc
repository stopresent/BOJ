#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;

void solve()
{
	cin >> N;

	// 인접 리스트 초기화 (1부터 N까지)
	vector<vector<int>> adj(N + 1, vector<int>());

	// N-1개의 간선 입력
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 부모 노드를 저장할 배열 (1부터 N까지)
	// 부모[1]은 루트이므로 0 또는 다른 값으로 초기화
	vector<int> parent(N + 1, 0);

	// 방문 여부를 확인할 배열
	vector<bool> visited(N + 1, false);

	// BFS를 위한 큐 초기화
	queue<int> q;
	q.push(1); // 루트 노드
	visited[1] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (auto& neighbor : adj[current]) {
			if (!visited[neighbor]) {
				parent[neighbor] = current; // 부모 설정
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}

	// 노드 2부터 N까지의 부모 출력
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}