#include <string>
#include <vector>

using namespace std;

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board[0].size();
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (board[y][x] != 1) continue;
            
            for (int i = 0; i < 8; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (board[ny][nx] != 1) board[ny][nx] = 2;
            }
        }
    }
    
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (board[y][x] == 0) answer++;
        }
    }
    return answer;
}