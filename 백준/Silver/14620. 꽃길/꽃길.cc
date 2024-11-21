#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, res = INT_MAX;
vector<vector<int>> board;
pair<int, int> coordi;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void solve()
{
	cin >> n;
	board = vector<vector<int>>(n, vector<int>(n));
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			cin >> board[y][x];
		}
	}

	// 3개 선택
	for (int i = 0; i < n * n - 2; ++i)
	{
		for (int j = i + 1; j < n * n - 1; ++j)
		{
			for (int k = j + 1; k < n * n; ++k)
			{
				// 1차원 인덱스를 2차원 좌표로 변환
				int row1 = i / n;
				int col1 = i % n;
				int row2 = j / n;
				int col2 = j % n;
				int row3 = k / n;
				int col3 = k % n;
				if (row1 == 0 || col1 == 0 || row1 == n - 1 || col1 == n - 1)
					continue;
				if (row2 == 0 || col2 == 0 || row2 == n - 1 || col2 == n - 1)
					continue;
				if (row3 == 0 || col3 == 0 || row3 == n - 1 || col3 == n - 1)
					continue;

				// 조합 저장
				set<pair<int, int>> s;
				int temp = 0;
				s.insert({ row1, col1 }); temp += board[row1][col1];
				s.insert({ row2, col2 }); temp += board[row2][col2];
				s.insert({ row3, col3 }); temp += board[row3][col3];
				for (int dir = 0; dir < 4; ++dir)
				{
					pair<int, int> n1 = { row1 + dy[dir], col1 + dx[dir] };
					pair<int, int> n2 = { row2 + dy[dir], col2 + dx[dir] };
					pair<int, int> n3 = { row3 + dy[dir], col3 + dx[dir] };
					s.insert(n1);
					s.insert(n2);
					s.insert(n3);
					temp += board[n1.first][n1.second];
					temp += board[n2.first][n2.second];
					temp += board[n3.first][n3.second];
				}
				// 꽃잎이 곂치는가?
				if (s.size() != 15)
					continue;

				// 비용 체크
				res = min(res, temp);
			}
		}
	}

	cout << res;
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