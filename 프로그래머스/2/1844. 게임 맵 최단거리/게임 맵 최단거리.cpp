#include <vector>
#include <queue>
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    maps[0][0] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == n - 1 && cur.second == m - 1)
            return maps[cur.first][cur.second];

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (maps[ny][nx] != 1) continue;

            maps[ny][nx] = maps[cur.first][cur.second] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    return -1;
}