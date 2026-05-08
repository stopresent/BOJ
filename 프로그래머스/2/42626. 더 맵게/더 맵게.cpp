#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K)
    {
        if (pq.size() < 2) return -1;
        int temp = pq.top();
        pq.pop();
        pq.push(temp + pq.top() * 2);
        pq.pop();
        answer++;
    }
    
    return answer;
}