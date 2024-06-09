#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
// 상하좌우 이동을 위한 배열
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

// 지도의 범위를 벗어나는지 확인하는 함수
bool isValid(int x, int y, int n, int m) 
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

// BFS를 이용하여 각 육지 칸에서의 최단 거리를 구하는 함수
int bfs(vector<vector<char>>& grid, int x, int y) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({ {x, y}, 0 });
    visited[x][y] = true;
    int maxDistance = 0;

    while (!q.empty()) 
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int distance = q.front().second;
        q.pop();
        maxDistance = max(maxDistance, distance);

        for (int i = 0; i < 4; ++i) 
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (isValid(nx, ny, n, m) && !visited[nx][ny] && grid[nx][ny] == 'L') 
            {
                q.push({ {nx, ny}, distance + 1 });
                visited[nx][ny] = true;
            }
        }
    }

    return maxDistance;
}

// 보물이 묻혀 있는 두 곳 사이의 최단 거리를 구하는 함수
int shortestTreasureDistance(vector<vector<char>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    int maxDistance = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (grid[i][j] == 'L') 
            {
                maxDistance = max(maxDistance, bfs(grid, i, j));
            }
        }
    }

    return maxDistance;
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board = vector<vector<char>>(n, vector<char>(m));
    // 예시 입력
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            cin >> board[y][x];
        }
    }

    // 최단 거리 출력
    cout << shortestTreasureDistance(board) << endl;  // 출력: 8

	return 0;
}