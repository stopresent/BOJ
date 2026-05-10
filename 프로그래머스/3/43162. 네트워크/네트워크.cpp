#include <string>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<bool> visited;

void DFS(int v)
{
    if (visited[v]) return;
    
    visited[v] = true;
    
    for (int x : A[v])
    {
        if (visited[x] == false)
            DFS(x);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    A.resize(n);
    visited = vector<bool>(n, false);
    
    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers.size(); j++)
        {
            if (computers[i][j] == 1)
            {
                A[i].push_back(j);
                A[j].push_back(i);
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            DFS(i);
            answer++;
        }
    }
    
    return answer;
}