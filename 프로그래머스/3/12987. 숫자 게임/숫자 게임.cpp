#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int start = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    queue<int> qa;
    queue<int> qb;
    for (int x : A)
        qa.push(x);
    for (int x : B)
        qb.push(x);
    
    while (!qb.empty())
    {
        if (qa.front() < qb.front())
        {
            qa.pop(); qb.pop();
            answer++;
        }
        else qb.pop();
    }

    return answer;
}