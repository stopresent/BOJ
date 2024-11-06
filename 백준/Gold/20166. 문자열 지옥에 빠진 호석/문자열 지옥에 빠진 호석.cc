#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


// 8방향 (상, 하, 좌, 우, 좌상, 우상, 좌하, 우하)
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int N, M, K;
vector<string> board;
map<string, int> m;

void search(int x, int y) 
{
	for (int i = 0; i < 8; i++) 
    { // 각 방향에 대해
		string cur = "";
		int cx = x, cy = y;

		for (int len = 0; len < K; len++) 
        { // 길이 K까지
			cur += board[cx][cy];
			m[cur]++;

			// 다음 위치로 이동
			cx = (cx + dx[i] + N) % N;
			cy = (cy + dy[i] + M) % M;
		}
	}
}

void solve()
{
    cin >> N >> M >> K;
    board.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    vector<string> v(K);
    for (int i = 0; i < K; i++) 
    {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            search(i, j);
        }
    }

    for (const auto& a : v) 
    {
        cout << m[a] << '\n';
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