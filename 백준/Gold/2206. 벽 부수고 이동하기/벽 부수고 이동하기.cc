#include <bits/stdc++.h>
using namespace std;

int N,M;
int board[1001][1001];
bool visited[1001][1001][2];
queue<pair<pair<int,int>,pair<int,int>>> q; // x,y좌표 및 벽부순 여부 , count(거리)
int dx[4] = {-1, 0, 1, 0}; // 상 우 하 좌
int dy[4] = {0, 1, 0, -1};
int bfs(){
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    q.push({{0,0},{0,1}}); //x,y와 벽 부순 횟수 0을 초기값으로 가짐.
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second.first;
        int count = q.front().second.second;
        q.pop();
        if(x == N-1 && y == M-1) { // 목적지에 도착하면 
            return count;
        }
        for(int a = 0; a<4; a++)
        {
            int nx = x + dx[a];
            int ny = y + dy[a];
            //맵을 벗어나지 않았고, nx,ny에 방문한 적이 없을 때.
            if(nx >=0 && nx <=N-1 && ny >=0 && ny <= M-1 && visited[nx][ny][wall]==false)
            {
                if(wall ==0 && board[nx][ny] ==0) // 벽을 한번도 부순적이 없고, 벽없는 곳을 갈때.
                {
                    visited[nx][ny][wall] =true;
                    q.push({{nx,ny},{0,count+1}});
                }
                else if(wall ==0 && board[nx][ny] ==1) // 벽을 한번도 부순적이 없고, 벽있는 곳을 갈때.
                {
                    visited[nx][ny][wall] =true;
                    q.push({{nx,ny},{1,count+1}});
                }
                else if(wall ==1 && board[nx][ny] ==0) // 벽을 한번 부쉈고(더이상 못부숨) 벽없는 곳을 갈때.
                {
                    visited[nx][ny][wall] =true;
                    q.push({{nx,ny},{1,count+1}});
                }
                else if(wall==1 && board[nx][ny] ==1) //벽을 한번 부쉈고, 벽없는 곳을 갈때. (더이상 진행불가)
                {
                    //do nothing.
                }
            }
        }
    }
    //목적지에 도착 못하면
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    //board setting
    for(int i = 0 ; i<N;i++)
    {
        string temp;
        cin >> temp;
        for(int j = 0 ; j<temp.size(); j++)
        {
            board[i][j] = temp[j]-'0';
        }
    }
    cout << bfs() ;


}