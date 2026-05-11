#include <string>
#include <vector>

using namespace std;

vector<bool> visited;
int answer = -1;
void DFS(vector<vector<int>>& dungeons, int curPirodo, int depth)
{
    if (answer < depth) answer = depth;
    
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visited[i]) continue;
        if (dungeons[i][0] <= curPirodo)
        {
            visited[i] = true;
            DFS(dungeons, curPirodo - dungeons[i][1], depth + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    visited = vector<bool>(dungeons.size(), false);
    for (int i = 0; i < dungeons.size(); i++)
    {
        visited = vector<bool>(dungeons.size(), false);
        DFS(dungeons, k, 0);
    }
    return answer;
}