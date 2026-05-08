#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
priority_queue<int> pq;
queue<pair<int, int>> q;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push({ priorities[i], i });
    }
    while (true)
    {
        int pqTop = pq.top();
        int qTop = q.front().first;
        if (pqTop == qTop)
        {
            answer++;
            if (q.front().second == location)
            {
                return answer;
            }
            pq.pop();
            q.pop();
        }
        else
        {
            pair<int, int> t = q.front();
            q.pop();
            q.push(t);
        }
    }
}